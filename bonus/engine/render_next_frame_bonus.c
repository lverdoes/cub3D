/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_next_frame_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 16:09:20 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/29 10:52:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	put_image_to_window(t_vars *vars)
{
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, vars->img.img);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.img, 0, 0);
	draw_hud(vars);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, vars->img.win);
}

static void	update_movement_and_view(t_vars *vars)
{
	t_key *k;
	t_pos *p;

	k = &vars->key;
	p = &vars->pos;
	if (k->key_w && !k->key_s)
		move_forward(vars);
	else if (k->key_s && !k->key_w)
		move_backwards(vars);
	if (k->key_a && !k->key_d)
		move_left(vars);
	else if (k->key_d && !k->key_a)
		move_right(vars);
	if (k->key_left && !k->key_right)
		view_left(vars);
	else if (k->key_right && !k->key_left)
		view_right(vars);
	if (k->key_down && !k->key_up && p->look_up >= -vars->img.height * 2)
		p->look_up -= VERT_SPEED;
	else if (k->key_up && !k->key_down && p->look_up <= vars->img.height * 2)
		p->look_up += VERT_SPEED;
	if (k->active_jump || k->key_jump || k->key_crouch)
		check_jump_crouch(vars);
	if (vars->mouse.click_left || vars->mouse.click_right)
		mouse_buttons(vars);
}

void		draw_walls(t_vars *vars)
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
		x++;
	}
}

void		draw_sprites(t_vars *vars)
{
	int i;

	i = 0;
	while (i < vars->map.sprite_count)
	{
		if (vars->map.sprites[i][4] == 1)
		{
			init_sprite_vars(vars, i);
			calc_sprite_height(vars);
			calc_sprite_width(vars);
			calc_sprite_dist(vars, i);
			calc_sprite_coordinates(vars, i, vars->spr.draw_start_x, 2);
		}
		i++;
	}
	ft_selection_sort(vars->map.sprites, vars->map.sprite_count);
}

int			render_next_frame(t_vars *vars)
{
	vars->hud.fps = calc_fps();
	if (!vars->hud.fps)
		error_msg(vars, "Unable to allocate memory for fps");
	vars->game.health -= 8;
	if (vars->game.health <= 0)
		close_program(vars);
	draw_background(vars);
	draw_walls(vars);
	draw_sprites(vars);
	update_movement_and_view(vars);
	coin_collect(vars);
	put_image_to_window(vars);
	return (1);
}
