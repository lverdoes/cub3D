/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_sprite_dist_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 14:24:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/29 10:56:14 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"
#include <math.h>

static void	swap(double *xp, double *yp)
{
	double tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

void		calc_sprite_dist(t_vars *vars, int i)
{
	double y;
	double x;

	y = vars->pos.pos_y - vars->map.sprites[i][0];
	if (y < 0)
		y = y * -1;
	x = vars->pos.pos_x - vars->map.sprites[i][1];
	if (x < 0)
		x = x * -1;
	vars->map.sprites[i][2] = sqrt(y * y + x * x);
}

void		ft_selection_sort(double **array, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		tmp = i;
		j = i + 1;
		while (j < len)
		{
			if (array[j][2] > array[tmp][2])
				tmp = j;
			j++;
		}
		swap(&array[tmp][0], &array[i][0]);
		swap(&array[tmp][1], &array[i][1]);
		swap(&array[tmp][2], &array[i][2]);
		swap(&array[tmp][3], &array[i][3]);
		swap(&array[tmp][4], &array[i][4]);
		i++;
	}
}
