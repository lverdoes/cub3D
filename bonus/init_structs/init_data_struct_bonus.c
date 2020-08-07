/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data_struct_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/21 10:56:56 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/23 09:14:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

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
	vars->game.loading_next = 0;
	vars->game.score_display = 0;
	vars->hud.fps = 0;
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
	init_misc_vars(vars);
}
