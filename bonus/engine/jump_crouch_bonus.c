/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   jump_crouch_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 09:07:20 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/17 16:51:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	jumping(t_vars *vars)
{
	t_key	*k;
	t_pos	*p;
	int		max_height;

	k = &vars->key;
	p = &vars->pos;
	max_height = vars->img.height / 2 * 0.8;
	if (p->jump >= max_height)
		k->active_jump = -1;
	else if (p->jump + JUMP_HEIGHT <= max_height)
	{
		p->jump += JUMP_HEIGHT;
		k->active_jump = 1;
	}
	else
	{
		p->jump = max_height;
		k->active_jump = -1;
	}
}

static void	landing(t_vars *vars)
{
	t_key	*k;
	t_pos	*p;

	k = &vars->key;
	p = &vars->pos;
	if (p->jump == 0)
	{
		k->active_jump = 0;
		p->move_speed = SPEED;
	}
	else if (p->jump - JUMP_HEIGHT > 0)
		p->jump -= JUMP_HEIGHT;
	else
	{
		p->jump = 0;
		k->active_jump = 0;
		p->move_speed = SPEED;
	}
}

static void	crouch(t_vars *vars)
{
	t_key	*k;
	t_pos	*p;
	int		min_height;

	k = &vars->key;
	p = &vars->pos;
	min_height = -vars->img.height / 2 * 0.8;
	k->active_jump = -2;
	if (p->jump - JUMP_HEIGHT > min_height)
		p->jump -= JUMP_HEIGHT;
}

void		check_jump_crouch(t_vars *vars)
{
	t_key *k;
	t_pos *p;

	k = &vars->key;
	p = &vars->pos;
	if (k->active_jump == 1)
		jumping(vars);
	else if (k->active_jump == -1)
		landing(vars);
	else if (k->key_jump && !k->key_crouch)
	{
		system("afplay ./sounds/jump.wav &");
		jumping(vars);
	}
	else if (k->key_crouch && !k->key_jump)
		crouch(vars);
	if (k->active_jump == -2)
		p->move_speed = SPEED / 5;
}
