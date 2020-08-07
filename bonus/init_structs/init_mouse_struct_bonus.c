/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mouse_struct_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/13 18:03:17 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/17 16:51:14 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	init_mouse_struct(t_vars *vars)
{
	t_mouse *m;

	m = &vars->mouse;
	m->prev_y = 0;
	m->prev_x = 0;
	m->min_x = 0;
	m->max_x = 0;
	m->click_left = 0;
	m->click_right = 0;
	m->click_middle = 0;
	m->scroll_down = 0;
	m->scroll_up = 0;
}
