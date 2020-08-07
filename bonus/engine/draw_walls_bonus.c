/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_walls_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 21:19:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/27 13:52:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void		get_texture_size(t_vars *vars)
{
	t_ray *r;

	r = &vars->ray;
	if (r->tex_side == 'N')
	{
		r->tex_width = vars->tex[0].width;
		r->tex_height = vars->tex[0].height;
	}
	else if (r->tex_side == 'E')
	{
		r->tex_width = vars->tex[1].width;
		r->tex_height = vars->tex[1].height;
	}
	else if (r->tex_side == 'S')
	{
		r->tex_width = vars->tex[2].width;
		r->tex_height = vars->tex[2].height;
	}
	else if (r->tex_side == 'W')
	{
		r->tex_width = vars->tex[3].width;
		r->tex_height = vars->tex[3].height;
	}
}

void		get_texture_x_coordinate(t_vars *vars)
{
	t_ray *r;
	t_pos *p;

	r = &vars->ray;
	p = &vars->pos;
	r->tex_step = 1.0 * r->tex_height / r->col_height;
	r->tex_pos = ((r->col_start - p->look_up - (p->jump / r->perp_wall_dist))
		- vars->img.height / 2 + r->col_height / 2) * r->tex_step;
	r->tex_x_coord = (int)(r->wall_x * (double)(r->tex_width));
	if (r->side == 0 && r->ray_dir_x > 0)
		r->tex_x_coord = r->tex_width - r->tex_x_coord - 1;
	if (r->side == 1 && r->ray_dir_y < 0)
		r->tex_x_coord = r->tex_width - r->tex_x_coord - 1;
}

static void	calc_texture_color(t_vars *vars, unsigned int *color, int x)
{
	t_ray *r;

	r = &vars->ray;
	*color = *(unsigned int*)(vars->tex[x].addr +
		(r->tex_y_coord * vars->tex[x].line_length + r->tex_x_coord
		* (vars->tex[x].bpp / 8)));
	add_shadow(vars, color, r->perp_wall_dist);
}

void		put_texture_to_image(t_vars *vars, int x)
{
	t_ray			*r;
	int				y;
	unsigned int	color;

	r = &vars->ray;
	y = r->col_start;
	while (y < r->col_end)
	{
		r->tex_y_coord = (int)r->tex_pos & (r->tex_height - 1);
		r->tex_pos += r->tex_step;
		if (r->tex_side == 'N')
			calc_texture_color(vars, &color, 0);
		else if (r->tex_side == 'E')
			calc_texture_color(vars, &color, 1);
		else if (r->tex_side == 'S')
			calc_texture_color(vars, &color, 2);
		else if (r->tex_side == 'W')
			calc_texture_color(vars, &color, 3);
		else if (r->tex_side == 'D')
			calc_texture_color(vars, &color, N_TEXTURES - 1);
		put_mlx_pixel(vars, x, y, color);
		y++;
	}
}
