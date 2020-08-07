/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 14:17:12 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/08/07 22:30:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size_of_src(char **array)
{
	size_t i;

	if (!array)
		return (0);
	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}

static char		**free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}

char			**ft_realloc(char **array, char *line)
{
	size_t	size;
	char	**dst;
	size_t	i;

	size = get_size_of_src(array);
	dst = ft_calloc(size + 2, sizeof(char *));
	if (!dst)
		return (free_array(array, size));
	i = 0;
	while (i < size)
	{
		dst[i] = array[i];
		i++;
	}
	free(array);
	dst[i] = ft_strdup(line);
	if (!dst[i])
		return (free_array(dst, i));
	return (dst);
}
