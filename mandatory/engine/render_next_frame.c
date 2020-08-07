/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_next_frame.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 16:09:20 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/29 11:21:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	put_image_to_window(t_img *img)
{
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, img->img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, img->win);
}

static void	update_movement_and_view(t_vars *vars)
{
	t_pos *p;

	p = &vars->pos;
	if (p->key_w && !p->key_s)
		move_forward(vars);
	else if (p->key_s && !p->key_w)
		move_backwards(vars);
	if (p->key_a && !p->key_d)
		move_left(vars);
	else if (p->key_d && !p->key_a)
		move_right(vars);
	if (p->key_left && !p->key_right)
		view_left(vars);
	else if (p->key_right && !p->key_left)
		view_right(vars);
}

void		raycast_walls(t_vars *vars)
{
	int x;

	x = 0;
	while (x < vars->img.width)
	{
		init_raycast_vars(vars, x);
		calc_ray_direction(vars);
		calc_dda(vars);
		calc_screen_column_height(vars);
		calc_dist_to_wall(vars, x);
		check_wall_side(vars);
		get_texture_size(vars);
		get_texture_x_coordinate(vars);
		put_texture_to_image(vars, x);
		put_background_to_image(vars, x);
		x++;
	}
}

void		raycast_sprites(t_vars *vars)
{
	int i;

	i = 0;
	while (i < vars->map.sprite_count)
	{
		init_sprite_vars(vars, i);
		calc_sprite_height(vars);
		calc_sprite_width(vars);
		calc_sprite_dist(vars);
		calc_sprite_coordinates(vars, vars->spr.draw_start_x);
		i++;
	}
}

int			render_next_frame(t_vars *vars)
{
	raycast_walls(vars);
	raycast_sprites(vars);
	update_movement_and_view(vars);
	put_image_to_window(&vars->img);
	return (1);
}
