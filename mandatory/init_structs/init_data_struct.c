/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data_struct.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/21 10:56:56 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/22 16:07:47 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	init_misc_vars(t_vars *vars)
{
	vars->map.map = 0;
	vars->map.sprites = 0;
	vars->bmp.fd = -1;
	vars->title.title = 0;
	vars->title.width = 0;
	vars->title.height = 0;
	vars->img.win = 0;
	vars->img.img = 0;
	vars->img.addr = 0;
	vars->ray.zbuffer = 0;
}

void		init_data_struct(t_vars *vars)
{
	size_t i;

	vars->data.fd = -1;
	vars->data.line = 0;
	vars->data.map = 0;
	vars->data.map_start = 0;
	vars->data.map_end = 0;
	vars->data.x_size = -1;
	vars->data.y_size = -1;
	vars->data.textures_fd = -1;
	i = 0;
	while (i < N_TEXTURES)
	{
		vars->data.text_path[i] = 0;
		vars->data.extension[i] = 0;
		i++;
	}
	vars->data.color_ceiling[0] = -1;
	vars->data.color_ceiling[1] = -1;
	vars->data.color_ceiling[2] = -1;
	vars->data.color_floor[0] = -1;
	vars->data.color_floor[1] = -1;
	vars->data.color_floor[2] = -1;
	init_misc_vars(vars);
}
