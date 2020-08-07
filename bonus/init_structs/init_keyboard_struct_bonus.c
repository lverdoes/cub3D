/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_keyboard_struct_bonus.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/13 21:44:45 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/20 16:47:45 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	init_keyboard_struct(t_vars *vars)
{
	t_key *k;

	k = &vars->key;
	k->key_w = 0;
	k->key_a = 0;
	k->key_s = 0;
	k->key_d = 0;
	k->key_left = 0;
	k->key_right = 0;
	k->key_down = 0;
	k->key_up = 0;
	k->key_jump = 0;
	k->key_crouch = 0;
	k->key_tab = 1;
	k->active_jump = 0;
}
