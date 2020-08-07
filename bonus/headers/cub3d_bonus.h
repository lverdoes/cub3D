/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 20:16:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/29 10:00:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "structs_bonus.h"
# include "libft.h"
# include <mlx.h>

/*
**  draw_hud_bonus.c
*/

void	draw_hud(t_vars *vars);

/*
**  jump_crouch_bonus.c
*/

void	check_jump_crouch(t_vars *vars);

/*
**  mouse_buttons_bonus.c
*/

void	mouse_buttons(t_vars *vars);

/*
**  next_level_bonus.c
*/

void	end_level(t_vars *vars);

/*
**  draw_background_bonus.c
*/

void	draw_background(t_vars *vars);

/*
**  coin_collect_bonus.c
*/

void	coin_collect(t_vars *vars);

/*
**	errors_and_free_bonus.c
*/

void	close_destroy_free(t_vars *vars);
void	error_msg(t_vars *vars, const char *str);
int		close_program(t_vars *vars);

/*
**	utilities_bonus.c
*/

size_t	strlen_nospace(char *str);
int		color_rgb(int r, int g, int b);
void	put_mlx_pixel(t_vars *vars, int x, int y, int color);
void	add_shadow(t_vars *vars, unsigned int *color, double distance);
char	*calc_fps(void);

/*
**	check_input_bonus.c
*/

void	check_input(t_vars *vars, int argc, char **argv);

/*
**	parse_lines_bonus.c
*/

void	parse_lines(t_vars *vars, char *line);

/*
**	get_res_tex_col_data_bonus.c
*/

void	get_resolution(t_vars *vars, char *str);
void	get_texture(t_vars *vars, char *str, size_t t);

/*
**	get_map_data_bonus.c
*/

void	get_map_data(t_vars *vars);

/*
**	flood_fill_bonus.c
*/

int		check_next(t_map *map, int row, int col, int prev);
int		check_path(t_map *map, int row, int col, int prev);
int		flood_fill(t_map *map, int row, int col, int prev);

/*
**	init_structs
*/

void	init_data_struct(t_vars *vars);
void	init_game_struct(t_vars *vars);
void	init_hud_struct(t_vars *vars);
void	init_image_struct(t_vars *vars, char *title);
void	init_keyboard_struct(t_vars *vars);
void	init_mouse_struct(t_vars *vars);
void	init_position_struct(t_vars *vars);
void	init_textures_struct(t_vars *vars);

/*
**	screenshot_bonus.c
*/

void	screenshot(t_vars *vars);

/*
**	render_next_frame_bonus.c
*/

void	draw_walls(t_vars *vars);
void	draw_sprites(t_vars *vars);
int		render_next_frame(t_vars *vars);

/*
**	track_key_input_bonus.c
*/

int		track_key_press(int key, t_vars *vars);
int		track_key_release(int key, t_vars *vars);
int		track_mouse_click(int button, int x, int y, t_vars *vars);
int		track_mouse_release(int button, int x, int y, t_vars *vars);
int		track_mouse_motion(int x, int y, t_vars *vars);

/*
**	movement_bonus.c
*/

void	move_forward(t_vars *vars);
void	move_backwards(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);

/*
**	view_bonus.c
*/

void	view_left(t_vars *vars);
void	view_right(t_vars *vars);

/*
**	calc_ray_dir_bonus.c
*/

void	init_raycast_vars(t_vars *vars, int x);
void	calc_ray_direction(t_vars *vars);
void	calc_dda(t_vars *vars);

/*
**	calc_wall_height_bonus.c
*/

void	calc_screen_column_height(t_vars *vars);
void	calc_dist_to_wall(t_vars *vars, int x);
void	check_wall_side(t_vars *vars);

/*
**	draw_walls_bonus.c
*/

void	get_texture_size(t_vars *vars);
void	get_texture_x_coordinate(t_vars *vars);
void	put_texture_to_image(t_vars *vars, int x);

/*
**	draw_sprites_bonus.c
*/

void	init_sprite_vars(t_vars *vars, int i);
void	calc_sprite_height(t_vars *vars);
void	calc_sprite_width(t_vars *vars);
void	calc_sprite_coordinates(t_vars *vars, int i, int x, int item);

/*
**  calc_sprite_dist_bonus.c
*/

void	ft_selection_sort(double **array, int len);
void	calc_sprite_dist(t_vars *vars, int i);

#endif
