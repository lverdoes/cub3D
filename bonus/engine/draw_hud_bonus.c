/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_hud_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 10:48:42 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/25 18:40:54 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	draw_text(t_vars *vars)
{
	t_game	*g;
	t_img	*i;
	t_hud	*h;

	g = &vars->game;
	i = &vars->img;
	h = &vars->hud;
	if (vars->game.score_display)
		free(vars->game.score_display);
	g->score = g->coins * 10;
	g->score_display = ft_itoa(g->score);
	if (!g->score_display)
		error_msg(vars, "Unable to allocate memory for score display");
	mlx_string_put(i->mlx, i->win, h->score_str_x,
		h->score_str_y, 0xffaa00, "Score: ");
	mlx_string_put(i->mlx, i->win, h->score_dis_x,
		h->score_dis_y, 0xffaa00, g->score_display);
	mlx_string_put(i->mlx, i->win, h->health_str_x,
		h->health_str_y, 0xFF0000, "Health: ");
}

static int	draw_lifebar(t_vars *vars, int y, int x, int len)
{
	t_img *i;
	t_hud *h;

	i = &vars->img;
	h = &vars->hud;
	if (y > h->bar_y_start && y < h->bar_y_end &&
		x > h->bar_x_start && x < h->bar_x_end &&
		x < h->bar_x_start + (len / 16))
		return (1);
	return (0);
}

static int	draw_life_rectangle(t_vars *vars, int y, int x)
{
	t_hud *h;

	h = &vars->hud;
	if (x == h->bar_x_start && y > h->bar_y_start && y < h->bar_y_end)
		return (1);
	else if (x == h->bar_x_end && y > h->bar_y_start && y < h->bar_y_end)
		return (1);
	else if (y == h->bar_y_start && x > h->bar_x_start && x < h->bar_x_end)
		return (1);
	else if (y == h->bar_y_end && x > h->bar_x_start && x < h->bar_x_end)
		return (1);
	return (0);
}

static void	draw_colors(t_vars *vars)
{
	t_hud	*h;
	t_img	*i;
	int		y;
	int		x;

	h = &vars->hud;
	i = &vars->img;
	y = h->bgr_y_start;
	while (y < h->bgr_y_end)
	{
		x = h->bgr_x_start;
		while (x < h->bgr_x_end)
		{
			if (draw_life_rectangle(vars, y, x))
				put_mlx_pixel(vars, x, y, 0x00000000);
			else if (draw_lifebar(vars, y, x, vars->game.health / 1))
				put_mlx_pixel(vars, x, y, 0x00FF0000);
			else
				put_mlx_pixel(vars, x, y, 1000000 * (x + 1) / (y * y));
			x++;
		}
		y++;
	}
}

void		draw_hud(t_vars *vars)
{
	t_hud *h;

	h = &vars->hud;
	if (vars->key.key_tab == 1)
	{
		mlx_mouse_hide();
		draw_colors(vars);
		draw_text(vars);
	}
	else
		mlx_mouse_show();
	mlx_string_put(vars->img.mlx, vars->img.win, 20, 20, 0xffaa00, "FPS: ");
	mlx_string_put(vars->img.mlx, vars->img.win, 70, 20, 0xffaa00, h->fps);
	if (h->fps)
		free(h->fps);
	h->fps = 0;
}
