/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game_struct_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/13 10:39:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/25 20:37:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	init_game_levels(t_vars *vars)
{
	size_t	i;
	t_game	*g;

	g = &vars->game;
	g->next_level = ft_calloc(N_LEVELS, sizeof(char *));
	if (!g->next_level)
		error_msg(vars, "Unable to allocate memory for next level (1)");
	g->next_level[0] = ft_strdup("cub3D_bonus");
	g->next_level[1] = ft_strdup("./maps_bonus/2_map_bonus.cub");
	g->next_level[2] = ft_strdup("./maps_bonus/3_map_bonus.cub");
	g->next_level[3] = ft_strdup("./maps_bonus/4_map_bonus.cub");
	i = 0;
	while (i < N_LEVELS)
	{
		if (!g->next_level[i])
			error_msg(vars, "Unable to allocate memory for next level");
		i++;
	}
}

void		init_game_struct(t_vars *vars)
{
	t_game		*g;
	static int	music = 1;

	if (music)
		system("afplay ./sounds/darkness.wav &");
	music = 0;
	g = &vars->game;
	g->total_coins = vars->map.total_coins;
	g->coins = 0;
	g->score = 0;
	g->health = HEALTH;
	g->ammo = 100;
	init_game_levels(vars);
}
