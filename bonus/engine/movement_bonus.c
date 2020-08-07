/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 17:13:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/17 11:02:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	move_forward(t_vars *vars)
{
	t_pos	*p;
	char	**map;
	int		tmp;

	p = &vars->pos;
	map = vars->data.map;
	tmp = (int)(p->pos_x + p->dir_x * p->move_speed);
	if (ft_charsearch(map[(int)p->pos_y][tmp], "049"))
		p->pos_x += p->dir_x * p->move_speed;
	tmp = (int)(p->pos_y + p->dir_y * p->move_speed);
	if (ft_charsearch(map[tmp][(int)p->pos_x], "049"))
		p->pos_y += p->dir_y * p->move_speed;
	if (map[(int)p->pos_y][(int)p->pos_x] == '9')
	{
		system("afplay ./sounds/door.wav &");
		map[(int)p->pos_y][(int)p->pos_x] = '0';
	}
}

void	move_backwards(t_vars *vars)
{
	t_pos	*p;
	char	**map;
	int		tmp;

	p = &vars->pos;
	map = vars->data.map;
	tmp = (int)(p->pos_x - p->dir_x * p->move_speed);
	if (ft_charsearch(map[(int)p->pos_y][tmp], "049"))
		p->pos_x -= p->dir_x * p->move_speed;
	tmp = (int)(p->pos_y - p->dir_y * p->move_speed);
	if (ft_charsearch(map[tmp][(int)p->pos_x], "049"))
		p->pos_y -= p->dir_y * p->move_speed;
	if (map[(int)p->pos_y][(int)p->pos_x] == '9')
	{
		system("afplay ./sounds/door.wav &");
		map[(int)p->pos_y][(int)p->pos_x] = '0';
	}
}

void	move_left(t_vars *vars)
{
	t_pos	*p;
	char	**map;
	int		tmp;

	p = &vars->pos;
	map = vars->data.map;
	tmp = (int)(p->pos_x + p->dir_y * p->move_speed);
	if (ft_charsearch(map[(int)p->pos_y][tmp], "049"))
		p->pos_x += p->dir_y * p->move_speed;
	tmp = (int)(p->pos_y - p->dir_x * p->move_speed);
	if (ft_charsearch(map[tmp][(int)p->pos_x], "049"))
		p->pos_y -= p->dir_x * p->move_speed;
	if (map[(int)p->pos_y][(int)p->pos_x] == '9')
	{
		system("afplay ./sounds/door.wav &");
		map[(int)p->pos_y][(int)p->pos_x] = '0';
	}
}

void	move_right(t_vars *vars)
{
	t_pos	*p;
	char	**map;
	int		tmp;

	p = &vars->pos;
	map = vars->data.map;
	tmp = (int)(p->pos_x - p->dir_y * p->move_speed);
	if (ft_charsearch(map[(int)p->pos_y][tmp], "049"))
		p->pos_x -= p->dir_y * p->move_speed;
	tmp = (int)(p->pos_y + p->dir_x * p->move_speed);
	if (ft_charsearch(map[tmp][(int)p->pos_x], "049"))
		p->pos_y += p->dir_x * p->move_speed;
	if (map[(int)p->pos_y][(int)p->pos_x] == '9')
	{
		system("afplay ./sounds/door.wav &");
		map[(int)p->pos_y][(int)p->pos_x] = '0';
	}
}
