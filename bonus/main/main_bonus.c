/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 20:14:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/25 21:09:24 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_vars vars;

	vars.game.next_level = 0;
	init_data_struct(&vars);
	check_input(&vars, argc, argv);
	init_position_struct(&vars);
	init_image_struct(&vars, argv[1]);
	init_textures_struct(&vars);
	if (vars.save)
		screenshot(&vars);
	init_keyboard_struct(&vars);
	init_mouse_struct(&vars);
	init_game_struct(&vars);
	init_hud_struct(&vars);
	mlx_loop_hook(vars.img.mlx, render_next_frame, &vars);
	mlx_hook(vars.img.win, 2, (1L << 0), track_key_press, &vars);
	mlx_hook(vars.img.win, 3, (1L << 1), track_key_release, &vars);
	mlx_hook(vars.img.win, 4, (1L << 2), track_mouse_click, &vars);
	mlx_hook(vars.img.win, 5, (1L << 3), track_mouse_release, &vars);
	mlx_hook(vars.img.win, 6, (1L << 6), track_mouse_motion, &vars);
	mlx_hook(vars.img.win, 17, (0L), close_program, &vars);
	mlx_loop(vars.img.mlx);
	exit(0);
}
