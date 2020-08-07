/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 12:04:27 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/20 16:33:39 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <math.h>

void		init_sprite_vars(t_vars *vars, int i)
{
	t_spr *s;
	t_pos *p;

	s = &vars->spr;
	p = &vars->pos;
	s->sprite_y = vars->map.sprites[i][0] - p->pos_y;
	s->sprite_x = vars->map.sprites[i][1] - p->pos_x;
	s->inv_det = 1.0 / (p->plane_x * p->dir_y - p->dir_x * p->plane_y);
	s->transform_x = s->inv_det
		* (p->dir_y * s->sprite_x - p->dir_x * s->sprite_y);
	s->transform_y = s->inv_det
		* (-p->plane_y * s->sprite_x + p->plane_x * s->sprite_y);
	s->sprite_screen_x = (vars->img.width / 2)
		* (1 + s->transform_x / s->transform_y);
}

void		calc_sprite_height(t_vars *vars)
{
	t_spr *s;
	t_img *i;

	s = &vars->spr;
	i = &vars->img;
	s->sprite_height = fabs(i->height / s->transform_y);
	s->draw_start_y = -s->sprite_height / 2 + i->height / 2;
	if (s->draw_start_y < 0)
		s->draw_start_y = 0;
	s->draw_end_y = s->sprite_height / 2 + i->height / 2;
	if (s->draw_end_y >= i->height)
		s->draw_end_y = i->height;
}

void		calc_sprite_width(t_vars *vars)
{
	t_spr *s;
	t_img *i;

	s = &vars->spr;
	i = &vars->img;
	s->sprite_width = fabs(i->height / s->transform_y);
	s->draw_start_x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_start_x < 0)
		s->draw_start_x = 0;
	s->draw_end_x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_end_x >= i->width)
		s->draw_end_x = i->width;
}

static void	put_sprite_to_image(t_vars *vars, int x, int y)
{
	t_spr			*s;
	unsigned int	color;

	s = &vars->spr;
	s->tex_y = ((y * 256 - vars->img.height *
		128 + s->sprite_height * 128) * vars->tex[4].height) /
		s->sprite_height / 256;
	color = *(unsigned int*)(vars->tex[4].addr + (s->tex_y *
		vars->tex[4].line_length + s->tex_x * (vars->tex[4].bpp / 8)));
	if ((color & 0x00FFFFFF) != 0)
		put_mlx_pixel(&vars->img, x, y, color);
}

void		calc_sprite_coordinates(t_vars *vars, int x)
{
	t_spr	*s;
	int		y;

	s = &vars->spr;
	while (x < s->draw_end_x)
	{
		s->tex_x = (256 * (x - (-s->sprite_width / 2 + s->sprite_screen_x))
			* vars->tex[4].width / s->sprite_width) / 256;
		y = s->draw_start_y;
		if (s->transform_y > 0 && x >= 0 && x < vars->img.width &&
			s->transform_y < vars->ray.zbuffer[x])
		{
			while (y < s->draw_end_y)
			{
				put_sprite_to_image(vars, x, y);
				y++;
			}
		}
		x++;
	}
}
