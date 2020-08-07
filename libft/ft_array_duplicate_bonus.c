/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array_duplicate_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 11:59:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/10 13:48:32 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size_of_src(char **array)
{
	size_t i;

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

char			**ft_array_duplicate(char **array)
{
	size_t	size;
	char	**dst;
	size_t	i;

	if (!array)
		return (0);
	size = get_size_of_src(array);
	dst = ft_calloc((size + 1), sizeof(char *));
	if (!dst)
		return (0);
	i = 0;
	while (i < size)
	{
		dst[i] = ft_strdup(array[i]);
		if (!dst[i])
			return (free_array(dst, i));
		i++;
	}
	return (dst);
}
