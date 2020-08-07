/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_res_tex_col_data_bonus.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 08:57:20 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/17 16:52:18 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"
#include <fcntl.h>
#include <unistd.h>

static size_t	move_index(t_vars *vars, char *str, size_t i, int color)
{
	while (str[i] == 32)
		i++;
	if (color == 0 && !ft_isdigit(str[i]))
		error_msg(vars, "Wrong input for resolution");
	if (color == 1 && !ft_isdigit(str[i]))
		error_msg(vars, "Wrong input for color(s)");
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == 32)
		i++;
	return (i);
}

void			get_resolution(t_vars *vars, char *str)
{
	size_t i;

	if (vars->data.x_size != -1 || vars->data.y_size != -1)
		error_msg(vars, "Multiple input lines for resolution");
	vars->data.x_size = ft_atoi(str + 0);
	i = move_index(vars, str, 0, 0);
	vars->data.y_size = ft_atoi(str + i);
	i = move_index(vars, str, i, 0);
	if (str[i] != '\0')
		error_msg(vars, "Wrong input for resolution");
	if (vars->data.x_size < 1)
		error_msg(vars, "Resolution size for x is too small");
	if (vars->data.y_size < 1)
		error_msg(vars, "Resolution size for y is too small");
}

static void		get_extension_type(t_vars *vars, char **dest, char **ext_type)
{
	char	buf[9];
	char	*ptr;

	ft_bzero(buf, 9);
	vars->data.textures_fd = open(*dest, O_RDONLY);
	if (&vars->data.textures_fd < 0)
		error_msg(vars, "Unable to open texture file");
	if (read(vars->data.textures_fd, buf, 8) < 0)
		error_msg(vars, "Unable to read texture file");
	if (close(vars->data.textures_fd) < 0)
		error_msg(vars, "Unable to close texture file");
	if (!ft_strnstr(buf, "PNG", 9) && !ft_strnstr(buf, "XPM", 9))
		error_msg(vars, "One or more image files have an invalid extension");
	ptr = ft_strrchr(*dest, '.');
	if (!ft_strncmp(ptr, ".png", 5) || !ft_strncmp(ptr, ".PNG", 5))
		*ext_type = ft_strdup(".png");
	else if (!ft_strncmp(ptr, ".xpm", 5) || !ft_strncmp(ptr, ".XPM", 5))
		*ext_type = ft_strdup(".xpm");
	else
		error_msg(vars, "Texture file is not .xpm or .png extension");
	if (!ext_type)
		error_msg(vars, "Unable to allocate memory in ext_type");
}

void			get_texture(t_vars *vars, char *str, size_t t)
{
	t_data	*d;
	size_t	i;

	d = &vars->data;
	if (d->text_path[t] != 0)
		error_msg(vars, "Multiple input lines for same textures");
	i = 0;
	while (str[i] == 32)
		i++;
	d->text_path[t] = ft_substr(str + i, 0, strlen_nospace(str + i));
	if (!d->text_path[t])
		error_msg(vars, "Unable to allocate memory in get_texture");
	get_extension_type(vars, &d->text_path[t], &d->extension[t]);
}
