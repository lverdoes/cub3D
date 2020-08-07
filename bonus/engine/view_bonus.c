/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 17:20:19 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/13 21:29:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"
#include <math.h>

void	view_left(t_vars *vars)
{
	t_pos	*p;
	double	tmp_dir_x;
	double	tmp_plane_x;

	p = &vars->pos;
	tmp_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-ROT_SPEED) - p->dir_y * sin(-ROT_SPEED);
	p->dir_y = tmp_dir_x * sin(-ROT_SPEED) + p->dir_y * cos(-ROT_SPEED);
	tmp_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-ROT_SPEED) -
		p->plane_y * sin(-ROT_SPEED);
	p->plane_y = tmp_plane_x * sin(-ROT_SPEED) +
		p->plane_y * cos(-ROT_SPEED);
}

void	view_right(t_vars *vars)
{
	t_pos	*p;
	double	tmp_dir_x;
	double	tmp_plane_x;

	p = &vars->pos;
	tmp_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(ROT_SPEED) - p->dir_y * sin(ROT_SPEED);
	p->dir_y = tmp_dir_x * sin(ROT_SPEED) + p->dir_y * cos(ROT_SPEED);
	tmp_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(ROT_SPEED) -
		p->plane_y * sin(ROT_SPEED);
	p->plane_y = tmp_plane_x * sin(ROT_SPEED) +
		p->plane_y * cos(ROT_SPEED);
}
