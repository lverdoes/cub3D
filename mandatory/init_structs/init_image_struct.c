/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_image_struct.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 14:17:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/25 20:41:49 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	init_window(t_vars *vars)
{
	t_img *i;

	i = &vars->img;
	i->img = mlx_new_image(i->mlx, i->width, i->height);
	if (!i->img)
		error_msg(vars, "Unable to create new image");
	i->addr = mlx_get_data_addr(i->img,
		&i->bpp, &i->line_length, &i->endian);
	if (!i->addr)
		error_msg(vars, "Invalid img.addr");
	if (vars->save)
		return ;
	i->win = mlx_new_window(i->mlx, i->width, i->height, vars->title.title);
	if (!i->win)
		error_msg(vars, "Unable to create new window");
}

static void	init_screen_resolution(t_vars *vars)
{
	t_img	*i;
	int		max_width;
	int		max_height;

	i = &vars->img;
	max_width = -1;
	max_height = -1;
	mlx_get_screen_size(i->mlx, &max_width, &max_height);
	if (vars->data.x_size > max_width && vars->save == 0 && max_width != -1)
		i->width = max_width;
	else
		i->width = vars->data.x_size;
	if (vars->data.y_size > max_height && vars->save == 0 && max_height != -1)
		i->height = max_height;
	else
		i->height = vars->data.y_size;
}

static void	create_window_title(t_vars *vars, char *cub)
{
	t_title	*t;
	t_img	*i;

	t = &vars->title;
	i = &vars->img;
	t->width = ft_itoa(i->width);
	if (!t->width)
		error_msg(vars, "Unable to allocate memory for title");
	t->height = ft_itoa(i->height);
	if (!t->height)
		error_msg(vars, "Unable to allocate memory for title");
	t->title = ft_strxjoin(6, "cub3D | ", cub, " | ", t->width, "x", t->height);
	if (!t->title)
		error_msg(vars, "Unable to allocate memory for title");
}

void		init_image_struct(t_vars *vars, char *cub)
{
	t_img	*i;
	int		*ceiling;
	int		*floor;

	i = &vars->img;
	ceiling = vars->data.color_ceiling;
	floor = vars->data.color_floor;
	init_screen_resolution(vars);
	create_window_title(vars, cub);
	i->mlx = mlx_init();
	if (!i->mlx)
		error_msg(vars, "Unable to init mlx");
	init_window(vars);
	i->c_color = col_rgb(ceiling[0], ceiling[1], ceiling[2]);
	i->f_color = col_rgb(floor[0], floor[1], floor[2]);
	vars->ray.zbuffer = ft_calloc(vars->img.width, sizeof(double));
	if (!vars->ray.zbuffer)
		error_msg(vars, "Unable to allocate memory for zbuffer");
}
