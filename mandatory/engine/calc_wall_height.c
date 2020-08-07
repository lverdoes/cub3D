/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_wall_height.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 20:37:41 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/27 13:49:56 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <math.h>

void	calc_screen_column_height(t_vars *vars)
{
	t_ray *r;

	r = &vars->ray;
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - vars->pos.pos_x +
		(1 - r->step_x) / 2) / r->ray_dir_x;
	else
		r->perp_wall_dist = (r->map_y - vars->pos.pos_y +
		(1 - r->step_y) / 2) / r->ray_dir_y;
	r->col_height = ((int)(vars->img.height) / r->perp_wall_dist);
	r->col_start = -r->col_height * 0.5 + vars->img.height / 2;
	if (r->col_start < 0)
		r->col_start = 0;
	else if (r->col_start >= vars->img.height)
		r->col_start = vars->img.height;
	r->col_end = r->col_height / 2 + vars->img.height / 2;
	if (r->col_end >= vars->img.height)
		r->col_end = vars->img.height;
	else if (r->col_end <= 0)
		r->col_end = 0;
}

void	calc_dist_to_wall(t_vars *vars, int x)
{
	t_ray *r;

	r = &vars->ray;
	if (r->side == 0)
		r->wall_x = vars->pos.pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_x = vars->pos.pos_x + r->perp_wall_dist * r->ray_dir_x;
	r->wall_x -= floor((r->wall_x));
	vars->ray.zbuffer[x] = vars->ray.perp_wall_dist;
}

void	check_wall_side(t_vars *vars)
{
	t_ray *r;
	t_pos *p;

	r = &vars->ray;
	p = &vars->pos;
	if (r->side == 0)
	{
		if (r->step_x > 0 && r->map_x > p->pos_x)
			r->tex_side = 'E';
		else if (r->step_x < 0 && r->map_x < p->pos_x)
			r->tex_side = 'W';
	}
	else if (r->side == 1)
	{
		if (r->step_y > 0 && r->map_y > p->pos_y)
			r->tex_side = 'S';
		else if (r->step_y < 0 && r->map_y < p->pos_y)
			r->tex_side = 'N';
	}
}
