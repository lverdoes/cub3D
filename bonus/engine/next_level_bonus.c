/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   next_level_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/13 21:59:18 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/27 13:15:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"
#include <unistd.h>

static void	new_level(t_vars *vars, int argc, char **argv)
{
	init_data_struct(vars);
	check_input(vars, argc, argv);
	init_position_struct(vars);
	init_image_struct(vars, argv[1]);
	init_textures_struct(vars);
	init_keyboard_struct(vars);
	init_mouse_struct(vars);
	init_game_struct(vars);
	init_hud_struct(vars);
	mlx_loop_hook(vars->img.mlx, render_next_frame, vars);
	mlx_hook(vars->img.win, 2, (1L << 0), track_key_press, vars);
	mlx_hook(vars->img.win, 3, (1L << 1), track_key_release, vars);
	mlx_hook(vars->img.win, 4, (1L << 2), track_mouse_click, vars);
	mlx_hook(vars->img.win, 5, (1L << 3), track_mouse_release, vars);
	mlx_hook(vars->img.win, 6, (1L << 6), track_mouse_motion, vars);
	mlx_hook(vars->img.win, 17, (0L), close_program, vars);
	mlx_loop(vars->img.mlx);
	exit(0);
}

void		end_level(t_vars *vars)
{
	static int	level = 0;
	char		*tmp;

	system("afplay ./sounds/level_end.wav &");
	level++;
	if (level >= N_LEVELS)
	{
		sleep(1);
		close_program(vars);
	}
	if (level >= 2)
	{
		tmp = vars->game.next_level[level];
		vars->game.next_level[level] = vars->game.next_level[1];
		vars->game.next_level[1] = tmp;
	}
	vars->game.loading_next = 1;
	close_destroy_free(vars);
	new_level(vars, 2, vars->game.next_level);
}
