/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_ray_dir.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 12:03:38 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/22 13:05:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <math.h>

void	init_raycast_vars(t_vars *vars, int x)
{
	t_ray *r;
	t_pos *p;

	r = &vars->ray;
	p = &vars->pos;
	r->camera = 2 * x / (double)vars->img.width - 1;
	r->ray_dir_x = p->dir_x + p->plane_x * r->camera;
	r->ray_dir_y = p->dir_y + p->plane_y * r->camera;
	r->map_x = (int)p->pos_x;
	r->map_y = (int)p->pos_y;
	r->delta_dist_x = fabs(1 / r->ray_dir_x);
	r->delta_dist_y = fabs(1 / r->ray_dir_y);
}

void	calc_ray_direction(t_vars *vars)
{
	t_ray *r;
	t_pos *p;

	r = &vars->ray;
	p = &vars->pos;
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (p->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - p->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (p->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - p->pos_y) * r->delta_dist_y;
	}
}

void	calc_dda(t_vars *vars)
{
	t_ray *r;

	r = &vars->ray;
	while (1)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (vars->data.map[r->map_y][r->map_x] == '1')
			return ;
	}
}
