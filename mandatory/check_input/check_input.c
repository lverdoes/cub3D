/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 21:30:18 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/18 13:47:56 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void	create_padded_map(t_vars *vars)
{
	char	*row;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (i < vars->map.max_row)
	{
		row = ft_calloc(vars->map.max_col + 1, sizeof(char));
		if (!row)
			error_msg(vars, "Unable to allocate memory to pad map");
		j = 0;
		while (j < vars->map.max_col)
		{
			row[j] = '0';
			len = ft_strlen(vars->data.map[i]);
			if (j < len && ft_charsearch(vars->data.map[i][j], "12"))
				row[j] = vars->data.map[i][j];
			j++;
		}
		free(vars->data.map[i]);
		vars->data.map[i] = row;
		i++;
	}
}

static void	read_cub_file(t_vars *vars, char *path)
{
	int gnl;

	vars->data.fd = open(path, O_RDONLY);
	if (vars->data.fd < 0)
		error_msg(vars, "Unable to open .cub file");
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(vars->data.fd, &vars->data.line);
		if (gnl < 0)
			error_msg(vars, "Get next line failed");
		parse_lines(vars, vars->data.line);
		free(vars->data.line);
	}
	vars->data.line = 0;
	if (close(vars->data.fd) < 0)
		error_msg(vars, "Unable to close .cub file");
	vars->data.fd = -1;
}

static void	check_arguments(t_vars *vars, int argc, char **argv)
{
	char *ptr;

	if (argc < 2)
		error_msg(vars, "Not enough arguments provided");
	if (argc >= 4)
		error_msg(vars, "Too many arguments provided");
	ptr = ft_strrchr(argv[1], '.');
	if (!ptr || ft_strncmp(ptr, ".cub", 5) != 0)
		error_msg(vars, "First argument is not a .cub file");
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7) == 0)
		vars->save = 1;
	else if (argc == 3)
		error_msg(vars, "Second argument can only be: \"--save\"");
	else
		vars->save = 0;
}

void		check_input(t_vars *vars, int argc, char **argv)
{
	check_arguments(vars, argc, argv);
	read_cub_file(vars, argv[1]);
	get_map_data(vars);
	if (!flood_fill(&vars->map, vars->map.spawn_row, vars->map.spawn_col, 0))
		error_msg(vars, "Map not enclosed by walls");
	create_padded_map(vars);
}
