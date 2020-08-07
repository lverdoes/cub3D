/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 20:16:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/29 11:20:39 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include "libft.h"
# include <mlx.h>

/*
**	errors_and_free.c
*/

void	error_msg(t_vars *vars, const char *str);
int		close_program(t_vars *vars);

/*
**	utilities.c
*/

size_t	strlen_nospace(char *str);
int		col_rgb(int r, int g, int b);
void	put_mlx_pixel(t_img *img, int x, int y, int color);

/*
**	check_input.c
*/

void	check_input(t_vars *vars, int argc, char **argv);

/*
**	parse_lines.c
*/

void	parse_lines(t_vars *vars, char *line);

/*
**	get_res_tex_col_data.c
*/

void	get_resolution(t_vars *vars, char *str);
void	get_color(t_vars *vars, int *colors, char *str);
void	get_texture(t_vars *vars, char *str, size_t t);

/*
**	get_map_data.c
*/

void	get_map_data(t_vars *vars);

/*
**	flood_fill.c
*/

int		check_next(t_map *map, int row, int col, int prev);
int		check_path(t_map *map, int row, int col, int prev);
int		flood_fill(t_map *map, int row, int col, int prev);

/*
**	initialize_structs.c
*/

void	init_data_struct(t_vars *vars);
void	init_image_struct(t_vars *vars, char *title);
void	init_position_struct(t_vars *vars);
void	init_textures_struct(t_vars *vars);

/*
**	take_screenshot.c
*/

void	screenshot(t_vars *vars);

/*
**	render_next_frame.c
*/

void	raycast_walls(t_vars *vars);
void	raycast_sprites(t_vars *vars);
int		render_next_frame(t_vars *vars);

/*
**	track_key_input.c
*/

int		track_key_press(int key, t_vars *vars);
int		track_key_release(int key, t_vars *vars);

/*
**	movement.c
*/

void	move_forward(t_vars *vars);
void	move_backwards(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);

/*
**	view.c
*/

void	view_left(t_vars *vars);
void	view_right(t_vars *vars);

/*
**	draw_walls.c
*/

void	init_raycast_vars(t_vars *vars, int x);
void	calc_ray_direction(t_vars *vars);
void	calc_dda(t_vars *vars);
void	calc_screen_column_height(t_vars *vars);
void	calc_dist_to_wall(t_vars *vars, int x);
void	check_wall_side(t_vars *vars);
void	get_texture_size(t_vars *vars);
void	get_texture_x_coordinate(t_vars *vars);
void	put_texture_to_image(t_vars *vars, int x);
void	put_background_to_image(t_vars *vars, int x);

/*
**	draw_sprites.c
*/

void	init_sprite_vars(t_vars *vars, int i);
void	calc_sprite_height(t_vars *vars);
void	calc_sprite_width(t_vars *vars);
void	calc_sprite_coordinates(t_vars *vars, int x);

/*
**  calc_sprite_dist.c
*/

void	calc_sprite_dist(t_vars *vars);

#endif
