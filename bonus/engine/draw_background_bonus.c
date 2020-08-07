/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_background_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 11:32:34 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/22 22:43:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	put_background_to_image(t_vars *vars, int x, int y)
{
	t_bgr			*b;
	unsigned int	color;
	int				tex;

	b = &vars->bgr;
	if (y < b->horizon + vars->pos.look_up)
		tex = 7;
	else
		tex = 8;
	color = *(unsigned int*)(vars->tex[tex].addr + (b->tex_y *
		vars->tex[tex].line_length + b->tex_x * (vars->tex[tex].bpp / 8)));
	add_shadow(vars, &color, b->row_distance);
	put_mlx_pixel(vars, x, y, color);
}

static void	row_loop(t_vars *vars, int y)
{
	t_bgr	*b;
	int		x;
	int		tex;

	b = &vars->bgr;
	x = 0;
	if (y < b->horizon + vars->pos.look_up)
		tex = 7;
	else
		tex = 8;
	while (x < vars->img.width)
	{
		b->cell_x = (int)(b->coord_x);
		b->cell_y = (int)(b->coord_y);
		b->tex_x = (int)(vars->tex[tex].width *
			(b->coord_x - b->cell_x)) & (vars->tex[tex].width - 1);
		b->tex_y = (int)(vars->tex[tex].height *
			(b->coord_y - b->cell_y)) & (vars->tex[tex].height - 1);
		b->coord_x += b->step_x;
		b->coord_y += b->step_y;
		put_background_to_image(vars, x, y);
		x++;
	}
}

static void	init_vertical_vars(t_vars *vars, int y)
{
	t_bgr	*b;

	b = &vars->bgr;
	if (y < b->horizon + vars->pos.look_up)
	{
		b->current_row = y - (vars->img.height / 2 + vars->pos.look_up);
		b->cam_z = b->horizon - b->jump;
		b->row_distance = 0 - b->cam_z / b->current_row;
	}
	else
	{
		b->current_row = y - (vars->img.height / 2 + vars->pos.look_up);
		b->cam_z = b->horizon + b->jump;
		b->row_distance = b->cam_z / b->current_row;
	}
}

static void	init_background_vars(t_vars *vars)
{
	t_bgr	*b;
	int		pix;

	b = &vars->bgr;
	pix = 128;
	b->ray_dir_x_0 = vars->pos.dir_x - vars->pos.plane_x;
	b->ray_dir_y_0 = vars->pos.dir_y - vars->pos.plane_y;
	b->ray_dir_x_1 = vars->pos.dir_x + vars->pos.plane_x;
	b->ray_dir_y_1 = vars->pos.dir_y + vars->pos.plane_y;
	b->horizon = 0.5 * vars->img.height;
	b->jump = vars->pos.jump;
}

void		draw_background(t_vars *vars)
{
	t_bgr	*b;
	int		y;

	b = &vars->bgr;
	y = 0;
	init_background_vars(vars);
	while (y < vars->img.height)
	{
		init_vertical_vars(vars, y);
		b->step_x = b->row_distance *
			(b->ray_dir_x_1 - b->ray_dir_x_0) / vars->img.width;
		b->step_y = b->row_distance *
			(b->ray_dir_y_1 - b->ray_dir_y_0) / vars->img.width;
		b->coord_x = vars->pos.pos_x + b->row_distance * b->ray_dir_x_0;
		b->coord_y = vars->pos.pos_y + b->row_distance * b->ray_dir_y_0;
		row_loop(vars, y);
		y++;
	}
}
