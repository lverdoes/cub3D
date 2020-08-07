/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 17:20:19 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/10 12:53:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <math.h>

void	view_left(t_vars *vars)
{
	t_pos	*p;
	double	tmp_dir_x;
	double	tmp_plane_x;

	p = &vars->pos;
	tmp_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-p->speed_rot) - p->dir_y * sin(-p->speed_rot);
	p->dir_y = tmp_dir_x * sin(-p->speed_rot) + p->dir_y * cos(-p->speed_rot);
	tmp_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-p->speed_rot) -
		p->plane_y * sin(-p->speed_rot);
	p->plane_y = tmp_plane_x * sin(-p->speed_rot) +
		p->plane_y * cos(-p->speed_rot);
}

void	view_right(t_vars *vars)
{
	t_pos	*p;
	double	tmp_dir_x;
	double	tmp_plane_x;

	p = &vars->pos;
	tmp_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(p->speed_rot) - p->dir_y * sin(p->speed_rot);
	p->dir_y = tmp_dir_x * sin(p->speed_rot) + p->dir_y * cos(p->speed_rot);
	tmp_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(p->speed_rot) -
		p->plane_y * sin(p->speed_rot);
	p->plane_y = tmp_plane_x * sin(p->speed_rot) +
		p->plane_y * cos(p->speed_rot);
}
