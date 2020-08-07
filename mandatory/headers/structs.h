/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 20:42:56 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/22 16:04:42 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define N_TEXTURES 5

# include <stdlib.h>

typedef struct		s_image{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	int				c_color;
	int				f_color;
}					t_img;

typedef struct		s_map{
	char			**map;
	size_t			max_row;
	size_t			max_col;
	int				spawns;
	size_t			spawn_row;
	size_t			spawn_col;
	char			spawn_dir;
	int				sprite_count;
	double			**sprites;
	int				big_map;
	int				big_y;
	int				big_x;
}					t_map;

typedef struct		s_data{
	int				fd;
	char			*line;
	char			**map;
	int				map_start;
	int				map_end;
	int				x_size;
	int				y_size;
	int				textures_fd;
	char			*text_path[N_TEXTURES];
	char			*extension[N_TEXTURES];
	int				color_ceiling[3];
	int				color_floor[3];
}					t_data;

typedef struct		s_title{
	char			*title;
	char			*width;
	char			*height;
}					t_title;

typedef struct		s_bitmap{
	int				fd;
	int				padding;
	unsigned int	size;
	int				offset;
	int				header_size;
	int				planes;
	int				bpp;
}					t_bmp;

typedef struct		s_position{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			speed_rot;
	double			speed_mov;
	int				speed_vert;
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_down;
	int				key_up;
}					t_pos;

typedef struct		s_textures{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_tex;

typedef struct		s_sprite{
	double			sprite_y;
	double			sprite_x;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
}					t_spr;

typedef struct		s_raycaster{
	double			*zbuffer;
	double			camera;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				side;
	int				col_height;
	int				col_start;
	int				col_end;
	double			wall_x;
	char			tex_side;
	int				tex_height;
	int				tex_width;
	double			tex_step;
	double			tex_pos;
	int				tex_x_coord;
	int				tex_y_coord;
}					t_ray;

typedef struct		s_vars{
	int				save;
	t_img			img;
	t_title			title;
	t_map			map;
	t_data			data;
	t_bmp			bmp;
	t_pos			pos;
	t_tex			tex[N_TEXTURES];
	t_spr			spr;
	t_ray			ray;
}					t_vars;

#endif
