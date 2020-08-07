/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map_data_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 10:13:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/13 21:52:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	get_sprite_data(t_vars *vars, size_t i, size_t j, size_t k)
{
	vars->map.sprites[k] = ft_calloc(5, sizeof(double));
	if (!vars->map.sprites[k])
	{
		ft_free_array((void **)vars->map.sprites, k);
		vars->map.sprites = 0;
		error_msg(vars, "Unable to allocate memory for sprite data");
	}
	vars->map.sprites[k][0] = (double)i + 0.5;
	vars->map.sprites[k][1] = (double)j + 0.5;
	vars->map.sprites[k][3] = (double)vars->map.map[i][j] - 48;
	vars->map.sprites[k][4] = 1;
	if (vars->map.sprites[k][3] == 4)
		vars->map.total_coins++;
}

static void	create_sprites(t_vars *vars, t_map *map)
{
	size_t i;
	size_t j;
	size_t k;

	map->sprites = ft_calloc(map->sprite_count, sizeof(double *));
	if (!map->sprites)
		error_msg(vars, "Unable to allocate memory for create_sprites");
	i = 0;
	k = 0;
	while (i < map->max_row)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (ft_charsearch(map->map[i][j], "234"))
			{
				get_sprite_data(vars, i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

static void	get_spawn_data(t_map *map, size_t i, size_t j)
{
	map->spawns++;
	map->spawn_row = i;
	map->spawn_col = j;
	map->spawn_dir = map->map[i][j];
}

static void	loop_through_map(t_vars *vars, t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	while (map->map[i] != 0)
	{
		map->max_row = i + 1;
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (j >= map->max_col)
				map->max_col = j + 1;
			if (ft_charsearch(map->map[i][j], "234"))
				map->sprite_count++;
			if (ft_charsearch(map->map[i][j], "NESW"))
				get_spawn_data(map, i, j);
			else if (!ft_charsearch(map->map[i][j], " 012349"))
				error_msg(vars, "Bad character(s) in map");
			j++;
		}
		i++;
	}
}

void		get_map_data(t_vars *vars)
{
	if (vars->data.map_start == 0)
		error_msg(vars, "No map found in .cub file");
	vars->map.map = ft_array_duplicate(vars->data.map);
	if (!vars->map.map)
		error_msg(vars, "Unable to allocate memory for map");
	vars->map.max_row = 0;
	vars->map.max_col = 0;
	vars->map.spawns = 0;
	vars->map.sprite_count = 0;
	vars->map.total_coins = 0;
	vars->map.big_map = 0;
	loop_through_map(vars, &vars->map);
	create_sprites(vars, &vars->map);
	if (vars->map.spawns < 1)
		error_msg(vars, "No start position given");
	if (vars->map.spawns > 1)
		error_msg(vars, "Multiple start positions given");
}
