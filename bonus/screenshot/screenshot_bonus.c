/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 15:46:57 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/25 21:09:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"
#include <unistd.h>
#include <fcntl.h>

static void	put_pixeldata(t_vars *vars)
{
	t_bmp			*b;
	int				i;
	int				j;
	unsigned int	color;

	b = &vars->bmp;
	i = vars->img.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < vars->img.width)
		{
			color = *(unsigned int*)(vars->img.addr +
				(i * vars->img.line_length + j *
				(vars->img.bpp / 8)));
			if (write(b->fd, &color, 3) != 3)
				error_msg(vars, "Unable to write pixel to file save.bmp");
			j++;
		}
		if (b->padding > 0 && write(b->fd, "\0\0\0", b->padding) != b->padding)
			error_msg(vars, "Unable to write padding to file save.bmp");
		i--;
	}
}

static void	put_fileheader(t_vars *vars)
{
	char header[54];

	ft_bzero(header, 54);
	ft_memcpy(header + 0, "B", 1);
	ft_memcpy(header + 1, "M", 1);
	ft_memcpy(header + 2, &vars->bmp.size, 4);
	ft_memcpy(header + 10, &vars->bmp.offset, 4);
	ft_memcpy(header + 14, &vars->bmp.header_size, 4);
	ft_memcpy(header + 18, &vars->img.width, 4);
	ft_memcpy(header + 22, &vars->img.height, 4);
	ft_memcpy(header + 26, &vars->bmp.planes, 2);
	ft_memcpy(header + 28, &vars->bmp.bpp, 2);
	if (write(vars->bmp.fd, header, 54) != 54)
		error_msg(vars, "Unable to write header to file save.bmp");
}

static void	init_bmp_struct(t_vars *vars)
{
	t_bmp	*b;
	int		pixels;

	b = &vars->bmp;
	b->padding = (4 - (vars->img.width * 3) % 4) % 4;
	pixels = vars->img.height * vars->img.width;
	b->size = 54 + (b->padding * vars->img.height) + 3 * pixels;
	b->offset = 54;
	b->header_size = 40;
	b->planes = 1;
	b->bpp = 24;
}

void		screenshot(t_vars *vars)
{
	init_bmp_struct(vars);
	vars->bmp.fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->bmp.fd < 0)
		error_msg(vars, "Unable to open/create file save.bmp");
	draw_background(vars);
	draw_walls(vars);
	draw_sprites(vars);
	put_fileheader(vars);
	put_pixeldata(vars);
	if (close(vars->bmp.fd) < 0)
		error_msg(vars, "Unable to close save.bmp");
	exit(0);
}
