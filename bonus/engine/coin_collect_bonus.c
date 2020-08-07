/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coin_collect_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 14:41:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/22 16:25:47 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	coin_collect(t_vars *vars)
{
	int		i;
	char	**map;

	map = vars->data.map;
	if (map[(int)vars->pos.pos_y][(int)vars->pos.pos_x] != '4')
		return ;
	i = vars->map.sprite_count - 1;
	vars->game.coins++;
	vars->game.health += 1000;
	if (vars->game.coins < vars->game.total_coins)
		system("afplay ./sounds/coin.mp3 &");
	else
		end_level(vars);
	while (i >= 0)
	{
		if ((int)vars->map.sprites[i][0] == (int)vars->pos.pos_y &&
			(int)vars->map.sprites[i][1] == (int)vars->pos.pos_x)
		{
			vars->map.sprites[i][4] = 0;
			vars->data.map[(int)vars->pos.pos_y][(int)vars->pos.pos_x] = '0';
			break ;
		}
		i--;
	}
}
