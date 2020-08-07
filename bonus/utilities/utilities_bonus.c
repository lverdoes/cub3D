/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 07:56:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/25 20:17:32 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"
#include <time.h>

size_t	strlen_nospace(char *str)
{
	size_t len;
	size_t i;

	len = ft_strlen(str);
	i = len - 1;
	while (str[i] == ' ')
	{
		str[i] = '\0';
		i--;
	}
	return (len);
}

int		color_rgb(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}

void	add_shadow(t_vars *vars, unsigned int *color, double distance)
{
	double			shade;
	unsigned int	red;
	unsigned int	gre;
	unsigned int	blu;

	if (!vars)
		return ;
	if (distance < 0)
		distance = distance * -1;
	shade = (6.0 / distance) / 5;
	if (shade > 1)
		shade = 1;
	else if (shade < 0.05)
		shade = 0.05;
	red = shade * (double)((*color >> 16) & 0x000000FF);
	gre = shade * (double)((*color >> 8) & 0x000000FF);
	blu = shade * (double)((*color) & 0x000000FF);
	*color = (unsigned int)color_rgb(red, gre, blu);
}

void	put_mlx_pixel(t_vars *vars, int x, int y, int color)
{
	char *dst;

	dst = vars->img.addr + (y * vars->img.line_length
		+ x * (vars->img.bpp / 8));
	*(unsigned int*)dst = color;
}

char	*calc_fps(void)
{
	static clock_t	start = 0;
	clock_t			difference;
	char			*fps;

	difference = clock() - start;
	start = clock();
	fps = ft_itoa(CLOCKS_PER_SEC / difference);
	if (!fps)
		return (0);
	return (fps);
}
