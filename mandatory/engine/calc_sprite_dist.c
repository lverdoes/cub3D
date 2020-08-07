/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_sprite_dist.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 14:24:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/29 13:13:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <math.h>

static void	swap(double *xp, double *yp)
{
	double tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

static void	sort_sprite(t_map *map)
{
	int i;

	i = 0;
	while (i < map->sprite_count - 1)
	{
		if (map->sprites[i][2] < map->sprites[i + 1][2])
		{
			swap(&map->sprites[i][0], &map->sprites[i + 1][0]);
			swap(&map->sprites[i][1], &map->sprites[i + 1][1]);
			swap(&map->sprites[i][2], &map->sprites[i + 1][2]);
		}
		i++;
	}
}

void		calc_sprite_dist(t_vars *vars)
{
	int		i;
	double	y;
	double	x;

	i = 0;
	while (i < vars->map.sprite_count)
	{
		y = vars->pos.pos_y - vars->map.sprites[i][0];
		if (y < 0)
			y = y * -1;
		x = vars->pos.pos_x - vars->map.sprites[i][1];
		if (x < 0)
			x = x * -1;
		vars->map.sprites[i][2] = sqrt(y * y + x * x);
		i++;
		sort_sprite(&vars->map);
	}
}
