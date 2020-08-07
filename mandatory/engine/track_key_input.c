/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   track_key_input.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 16:51:21 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/10 12:53:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	track_key_press(int key, t_vars *vars)
{
	t_pos *p;

	p = &vars->pos;
	if (key == 13)
		p->key_w = 1;
	else if (key == 1)
		p->key_s = 1;
	if (key == 0)
		p->key_a = 1;
	else if (key == 2)
		p->key_d = 1;
	if (key == 123)
		p->key_left = 1;
	else if (key == 124)
		p->key_right = 1;
	if (key == 53)
		close_program(vars);
	return (1);
}

int	track_key_release(int key, t_vars *vars)
{
	t_pos *p;

	p = &vars->pos;
	if (key == 13)
		p->key_w = 0;
	if (key == 1)
		p->key_s = 0;
	if (key == 0)
		p->key_a = 0;
	if (key == 2)
		p->key_d = 0;
	if (key == 123)
		p->key_left = 0;
	if (key == 124)
		p->key_right = 0;
	return (1);
}
