/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_hud_struct_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 09:10:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/23 09:25:58 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	init_hud_struct(t_vars *vars)
{
	t_hud *h;
	t_img *i;

	h = &vars->hud;
	i = &vars->img;
	h->bgr_y_start = i->height - 80 - h->offset;
	h->bgr_y_end = i->height;
	h->bgr_x_start = 0;
	h->bgr_x_end = i->width;
	h->bar_y_start = i->height - 51 - h->offset;
	h->bar_y_end = i->height - 20 - h->offset;
	h->bar_x_start = 100;
	h->bar_x_end = i->width - 100;
	h->score_str_y = i->height - 60 - h->offset;
	h->score_str_x = 20;
	h->score_dis_y = i->height - 60 - h->offset;
	h->score_dis_x = 90;
	h->health_str_y = i->height - 30 - h->offset;
	h->health_str_x = 20;
	h->life_y_start = i->height - 50 - h->offset;
	h->life_y_end = i->height - 20 - h->offset;
	h->life_x_start = 100;
}
