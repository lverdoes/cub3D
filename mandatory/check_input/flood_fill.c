/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 11:48:25 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/10 12:53:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int			check_next(t_map *map, int row, int col, int prev)
{
	static int call_count = 0;

	call_count += 1;
	if (call_count >= 42000)
	{
		map->big_map = 1;
		call_count = 0;
		return (0);
	}
	if (row < 0 || col < 0 || (size_t)row >= map->max_row || map->big_map == 1
		|| (size_t)col >= ft_strlen(map->map[row]))
		return (0);
	if (ft_charsearch(map->map[row][col], "1X")
		|| map->map[row][col] == map->spawn_dir)
		return (1);
	if (ft_charsearch(map->map[row][col], "02"))
	{
		map->map[row][col] = 'X';
		if (check_path(map, row, col, prev))
			return (1);
	}
	return (0);
}

int			check_path(t_map *map, int row, int col, int prev)
{
	if (prev != 2 && !check_next(map, row - 1, col, 1))
		return (0);
	if (prev != 1 && !check_next(map, row + 1, col, 2))
		return (0);
	if (prev != 4 && !check_next(map, row, col - 1, 3))
		return (0);
	if (prev != 3 && !check_next(map, row, col + 1, 4))
		return (0);
	if (prev != 2 && prev != 4 && prev != 8 &&
		!check_next(map, row - 1, col - 1, 5))
		return (0);
	if (prev != 2 && prev != 3 && prev != 7 &&
		!check_next(map, row - 1, col + 1, 6))
		return (0);
	if (prev != 1 && prev != 4 && prev != 6 &&
		!check_next(map, row + 1, col - 1, 7))
		return (0);
	if (prev != 1 && prev != 3 && prev != 5 &&
		!check_next(map, row + 1, col + 1, 8))
		return (0);
	return (1);
}

static int	adjacent(char **map, int i, int j)
{
	if (map[i][j] == 'X')
	{
		if (ft_charsearch(map[i - 1][j], "02")
		|| ft_charsearch(map[i + 1][j], "02")
		|| ft_charsearch(map[i][j - 1], "02")
		|| ft_charsearch(map[i][j + 1], "02")
		|| ft_charsearch(map[i - 1][j - 1], "02")
		|| ft_charsearch(map[i + 1][j + 1], "02")
		|| ft_charsearch(map[i - 1][j + 1], "02")
		|| ft_charsearch(map[i + 1][j - 1], "02"))
			return (1);
	}
	return (0);
}

static int	tile_loop(t_map *map)
{
	size_t y;
	size_t x;
	size_t len;

	y = 0;
	while (y < map->max_row)
	{
		x = 0;
		len = ft_strlen(map->map[y]);
		while (x < len)
		{
			if (adjacent(map->map, y, x))
			{
				map->big_y = y;
				map->big_x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			flood_fill(t_map *map, int row, int col, int prev)
{
	int ret;

	ret = check_path(map, row, col, prev);
	if (ret == 0 && map->big_map == 0)
		return (0);
	else if (ret == 0 && map->big_map == 1)
	{
		map->big_map = 0;
		tile_loop(map);
		return (flood_fill(map, map->big_y, map->big_x, 0));
	}
	if (ret == 1)
	{
		if (!tile_loop(map))
			return (1);
		return (flood_fill(map, map->big_y, map->big_x, 0));
	}
	return (0);
}
