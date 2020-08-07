/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 07:56:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/22 16:06:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

size_t	strlen_nospace(char *str)
{
	size_t len;
	size_t i;

	len = ft_strlen(str);
	i = len - 1;
	while (str[i] == ' ')
	{
		str[i] = '\0';
		i--;
	}
	return (len);
}

int		col_rgb(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}

void	put_mlx_pixel(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}
