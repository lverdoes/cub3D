/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 17:13:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/10 12:53:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	move_forward(t_vars *vars)
{
	t_pos	*p;
	char	**map;
	int		tmp;

	p = &vars->pos;
	map = vars->data.map;
	tmp = (int)(p->pos_x + p->dir_x * p->speed_mov);
	if (map[(int)p->pos_y][tmp] == '0')
		p->pos_x += p->dir_x * p->speed_mov;
	tmp = (int)(p->pos_y + p->dir_y * p->speed_mov);
	if (map[tmp][(int)p->pos_x] == '0')
		p->pos_y += p->dir_y * p->speed_mov;
}

void	move_backwards(t_vars *vars)
{
	t_pos	*p;
	char	**map;
	int		tmp;

	p = &vars->pos;
	map = vars->data.map;
	tmp = (int)(p->pos_x - p->dir_x * p->speed_mov);
	if (map[(int)p->pos_y][tmp] == '0')
		p->pos_x -= p->dir_x * p->speed_mov;
	tmp = (int)(p->pos_y - p->dir_y * p->speed_mov);
	if (map[tmp][(int)p->pos_x] == '0')
		p->pos_y -= p->dir_y * p->speed_mov;
}

void	move_left(t_vars *vars)
{
	t_pos	*p;
	char	**map;
	int		tmp;

	p = &vars->pos;
	map = vars->data.map;
	tmp = (int)(p->pos_x + p->dir_y * p->speed_mov);
	if (map[(int)p->pos_y][tmp] == '0')
		p->pos_x += p->dir_y * p->speed_mov;
	tmp = (int)(p->pos_y - p->dir_x * p->speed_mov);
	if (map[tmp][(int)p->pos_x] == '0')
		p->pos_y -= p->dir_x * p->speed_mov;
}

void	move_right(t_vars *vars)
{
	t_pos	*p;
	char	**map;
	int		tmp;

	p = &vars->pos;
	map = vars->data.map;
	tmp = (int)(p->pos_x - p->dir_y * p->speed_mov);
	if (map[(int)p->pos_y][tmp] == '0')
		p->pos_x -= p->dir_y * p->speed_mov;
	tmp = (int)(p->pos_y + p->dir_x * p->speed_mov);
	if (map[tmp][(int)p->pos_x] == '0')
		p->pos_y += p->dir_x * p->speed_mov;
}
