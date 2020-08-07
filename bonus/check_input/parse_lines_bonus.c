/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_lines_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 07:34:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/27 13:53:22 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static int	check_parsed_data(t_vars *vars)
{
	t_data	*d;
	size_t	i;

	d = &vars->data;
	if (d->x_size < 1)
		return (0);
	if (d->y_size < 1)
		return (0);
	i = 0;
	while (i < N_TEXTURES)
	{
		if (!d->text_path[i])
			return (0);
		i++;
	}
	i = 0;
	return (1);
}

static void	parse_bonus_textures(t_vars *vars, char *line, size_t i)
{
	if (line[i] == 'S' && line[i + 1] == '3')
		get_texture(vars, line + i + 2, 5);
	else if (line[i] == 'S' && line[i + 1] == '4')
		get_texture(vars, line + i + 2, 6);
	else if (line[i] == 'C')
		get_texture(vars, line + i + 1, 7);
	else if (line[i] == 'F')
		get_texture(vars, line + i + 1, 8);
	else if (line[i] == 'S' && line[i + 1] == 'D')
		get_texture(vars, line + i + 2, N_TEXTURES - 1);
	else
		error_msg(vars, "Unidentified input in .cub file");
}

static void	parse_mandatory_data(t_vars *vars, char *line, size_t i)
{
	if (line[i] == 'R')
		get_resolution(vars, line + i + 1);
	else if (line[i] == 'N' && line[i + 1] == 'O')
		get_texture(vars, line + i + 2, 0);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		get_texture(vars, line + i + 2, 1);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		get_texture(vars, line + i + 2, 2);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		get_texture(vars, line + i + 2, 3);
	else if (line[i] == 'S' && !ft_charsearch(line[i + 1], "O34D"))
		get_texture(vars, line + i + 1, 4);
	else
		parse_bonus_textures(vars, line, i);
}

static void	parse_map_data(t_vars *vars, char *line)
{
	if (vars->data.map_end == 1)
		error_msg(vars, "Map content cannot be interrupted");
	if (vars->data.map_start == 0 && !check_parsed_data(vars))
		error_msg(vars, "Expected more information before map content");
	vars->data.map_start++;
	vars->data.map = ft_realloc(vars->data.map, line);
	if (!vars->data.map)
		error_msg(vars, "Unable to (re)allocate memory for map");
}

void		parse_lines(t_vars *vars, char *line)
{
	size_t i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_charsearch(line[i], "01239"))
	{
		parse_map_data(vars, line);
		return ;
	}
	if (vars->data.map_start > 0)
		vars->data.map_end = 1;
	if (line[0] == '\0')
		return ;
	else
		parse_mandatory_data(vars, line, i);
}
