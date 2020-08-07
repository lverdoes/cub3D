/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_textures_struct_bonus.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 15:00:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/20 11:19:14 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	get_file_to_image(t_vars *vars, char *ext, char *path, size_t i)
{
	if (!ft_strncmp(ext, ".png", 5))
	{
		vars->tex[i].img = mlx_png_file_to_image(vars->img.mlx,
		path, &vars->tex[i].width, &vars->tex[i].height);
	}
	else if (!ft_strncmp(ext, ".xpm", 5))
		vars->tex[i].img = mlx_xpm_file_to_image(vars->img.mlx,
		path, &vars->tex[i].width, &vars->tex[i].height);
	else
		error_msg(vars, "Textures file is not .png or .xpm");
	if (!vars->tex[i].img)
		error_msg(vars, "Unable to create ptr to tex file");
}

static void	resize_texture(t_vars *vars, size_t i)
{
	t_tex	*t;
	int		pixels_1;
	int		pixels_2;

	t = &vars->tex[i];
	pixels_1 = 1024;
	pixels_2 = 64;
	if (t->width > pixels_1)
		t->width = t->width - (t->width % pixels_1);
	else if (t->width > pixels_2)
		t->width = t->width - (t->width % pixels_2);
	if (t->height > pixels_1)
		t->height = t->height - (t->height % pixels_1);
	else if (t->height > pixels_2)
		t->height = t->height - (t->height % pixels_2);
}

void		init_textures_struct(t_vars *vars)
{
	t_data	*d;
	size_t	i;

	d = &vars->data;
	i = 0;
	while (i < N_TEXTURES)
	{
		get_file_to_image(vars, d->extension[i], d->text_path[i], i);
		if (!vars->tex[i].img)
			error_msg(vars, "Unable to load textures to image");
		vars->tex[i].addr = mlx_get_data_addr(vars->tex[i].img,
		&vars->tex[i].bpp, &vars->tex[i].line_length, &vars->tex[i].endian);
		if (!vars->tex[i].addr)
			error_msg(vars, "Unable to find textures adress");
		resize_texture(vars, i);
		free(d->text_path[i]);
		d->text_path[i] = 0;
		free(d->extension[i]);
		d->extension[i] = 0;
		i++;
	}
}
