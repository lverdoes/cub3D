/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors_and_free.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 16:15:40 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/22 16:04:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <unistd.h>

static void	free_map_title(t_vars *vars)
{
	if (vars->map.map)
		ft_free_array((void **)vars->map.map, vars->data.map_start);
	if (vars->map.sprites)
		ft_free_array((void **)vars->map.sprites, vars->map.sprite_count);
	if (vars->title.title)
		free(vars->title.title);
	if (vars->title.width)
		free(vars->title.width);
	if (vars->title.height)
		free(vars->title.height);
	if (vars->ray.zbuffer)
		free(vars->ray.zbuffer);
}

static void	free_data_struct(t_vars *vars)
{
	size_t i;

	if (vars->data.line)
		free(vars->data.line);
	if (vars->data.map)
		ft_free_array((void **)vars->data.map, vars->data.map_start);
	i = 0;
	while (i < N_TEXTURES)
	{
		if (vars->data.text_path[i])
			free(vars->data.text_path[i]);
		if (vars->data.extension[i])
			free(vars->data.extension[i]);
		i++;
	}
	if (vars->data.fd != -1)
		close(vars->data.fd);
	if (vars->data.textures_fd != -1)
		close(vars->data.textures_fd);
	if (vars->bmp.fd != -1)
		close(vars->bmp.fd);
}

static void	close_destroy_free(t_vars *vars)
{
	if (vars->img.win)
		mlx_destroy_window(vars->img.mlx, vars->img.win);
	if (vars->img.img)
		mlx_destroy_image(vars->img.mlx, vars->img.img);
	free_map_title(vars);
	free_data_struct(vars);
}

void		error_msg(t_vars *vars, const char *str)
{
	close_destroy_free(vars);
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

int			close_program(t_vars *vars)
{
	close_destroy_free(vars);
	exit(0);
}
