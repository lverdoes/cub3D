/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   track_key_input_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 16:51:21 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/20 16:49:08 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

int	track_key_press(int key, t_vars *vars)
{
	if (key == 13)
		vars->key.key_w = 1;
	else if (key == 1)
		vars->key.key_s = 1;
	if (key == 0)
		vars->key.key_a = 1;
	else if (key == 2)
		vars->key.key_d = 1;
	if (key == 123)
		vars->key.key_left = 1;
	else if (key == 124)
		vars->key.key_right = 1;
	if (key == 125)
		vars->key.key_down = 1;
	else if (key == 126)
		vars->key.key_up = 1;
	if (key == 49)
		vars->key.key_jump = 1;
	else if (key == 8)
		vars->key.key_crouch = 1;
	if (key == 48)
		vars->key.key_tab = -vars->key.key_tab;
	if (key == 53)
		close_program(vars);
	return (1);
}

int	track_key_release(int key, t_vars *vars)
{
	if (key == 13)
		vars->key.key_w = 0;
	if (key == 1)
		vars->key.key_s = 0;
	if (key == 0)
		vars->key.key_a = 0;
	if (key == 2)
		vars->key.key_d = 0;
	if (key == 123)
		vars->key.key_left = 0;
	if (key == 124)
		vars->key.key_right = 0;
	if (key == 125)
		vars->key.key_down = 0;
	if (key == 126)
		vars->key.key_up = 0;
	if (key == 49)
		vars->key.key_jump = 0;
	if (key == 8)
		vars->key.key_crouch = 0;
	return (1);
}

int	track_mouse_click(int button, int x, int y, t_vars *vars)
{
	t_mouse	*m;
	int		h;
	int		w;

	m = &vars->mouse;
	h = vars->img.height;
	w = vars->img.width;
	if (x >= 0 && x < w && y >= 0 && y < h)
	{
		if (button == 1)
			m->click_left = 1;
		else if (button == 2)
			m->click_right = 1;
		else if (button == 3)
			m->click_middle = 1;
		else if (button == 4)
			m->scroll_down = 1;
		else if (button == 5)
			m->scroll_up = 1;
	}
	return (1);
}

int	track_mouse_release(int button, int x, int y, t_vars *vars)
{
	t_mouse	*m;

	if (x < 0 || x > vars->img.width || y < 0 || y > vars->img.height)
		return (1);
	m = &vars->mouse;
	if (button == 1)
		m->click_left = 0;
	else if (button == 2)
		m->click_right = 0;
	else if (button == 3)
		m->click_middle = 0;
	else if (button == 4)
		m->scroll_down = 0;
	else if (button == 5)
		m->scroll_up = 0;
	return (1);
}

int	track_mouse_motion(int x, int y, t_vars *vars)
{
	t_mouse *m;

	m = &vars->mouse;
	vars->pos.look_up -= 2 * (y - m->prev_y);
	m->prev_y = y;
	if (x < m->min_x)
		m->min_x = x;
	else if (x > m->max_x)
		m->max_x = x;
	if (x == 0)
		view_left(vars);
	else if (x == vars->img.width - 1)
		view_right(vars);
	else if (x < m->prev_x || x == m->min_x)
		view_left(vars);
	else if (x > m->prev_x || x == m->max_x)
		view_right(vars);
	m->prev_x = x;
	if (y < 0)
	{
		m->min_x = 0;
		m->max_x = 0;
	}
	return (1);
}
