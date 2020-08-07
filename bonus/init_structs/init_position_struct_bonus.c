/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_position_struct_bonus.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 14:24:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/15 18:56:01 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	view_north_on_spawn(t_pos *pos)
{
	pos->dir_x = 0;
	pos->dir_y = -1;
	pos->plane_x = 0.66;
	pos->plane_y = 0;
}

static void	view_south_on_spawn(t_pos *pos)
{
	pos->dir_x = 0;
	pos->dir_y = 1;
	pos->plane_x = -0.66;
	pos->plane_y = 0;
}

static void	view_west_on_spawn(t_pos *pos)
{
	pos->dir_x = -1;
	pos->dir_y = 0;
	pos->plane_x = 0;
	pos->plane_y = -0.66;
}

static void	view_east_on_spawn(t_pos *pos)
{
	pos->dir_x = 1;
	pos->dir_y = 0;
	pos->plane_x = 0;
	pos->plane_y = 0.66;
}

void		init_position_struct(t_vars *vars)
{
	t_pos *p;

	p = &vars->pos;
	p->pos_x = vars->map.spawn_col + 0.49;
	p->pos_y = vars->map.spawn_row + 0.49;
	p->move_speed = SPEED;
	p->look_up = 0;
	p->jump = 0;
	if (vars->map.spawn_dir == 'N')
		view_north_on_spawn(p);
	else if (vars->map.spawn_dir == 'S')
		view_south_on_spawn(p);
	else if (vars->map.spawn_dir == 'W')
		view_west_on_spawn(p);
	else if (vars->map.spawn_dir == 'E')
		view_east_on_spawn(p);
}
