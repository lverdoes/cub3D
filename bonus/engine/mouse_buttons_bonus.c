/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_buttons_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 09:22:53 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/17 08:07:33 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	mouse_buttons(t_vars *vars)
{
	if (vars->mouse.click_left && vars->game.ammo > 0)
		vars->game.ammo--;
	else if (vars->mouse.click_right)
		vars->game.ammo = 100;
}
