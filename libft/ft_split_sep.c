/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_sep.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 08:58:49 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/17 16:46:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(const char *src, char *sep, size_t i)
{
	while (src[i] != '\0' && ft_charsearch(src[i], sep))
		i++;
	return (i);
}

static size_t	get_len(const char *src, char *sep, size_t start)
{
	size_t i;
	size_t len;

	i = start;
	len = 0;
	while (src[i] != '\0' && !ft_charsearch(src[i], sep))
	{
		i++;
		len++;
	}
	return (len);
}

static size_t	count_strings(const char *src, char *sep)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (ft_strlen(sep) == 0 && src[i] != '\0')
		return (1);
	while (src[i] != '\0')
	{
		if (!ft_charsearch(src[i], sep))
		{
			count++;
			while (!ft_charsearch(src[i], sep) && src[i] != '\0')
				i++;
		}
		while (ft_charsearch(src[i], sep))
			i++;
	}
	return (count);
}

static int		init_dst(char **dst, const char *src, char *sep, size_t size)
{
	size_t i;
	size_t start;
	size_t len;

	i = 0;
	start = 0;
	len = 0;
	while (i < size)
	{
		start = get_start(src, sep, start + len);
		len = get_len(src, sep, start);
		dst[i] = ft_substr(src, start, len);
		if (!dst[i])
			return (ft_free_array((void **)dst, i));
		i++;
	}
	return (1);
}

char			**ft_split_sep(const char *src, char *sep, size_t *size)
{
	char **dst;

	if (!src)
		return (0);
	*size = count_strings(src, sep);
	dst = ft_calloc((*size + 1), sizeof(char*));
	if (!dst)
		return (0);
	if (!init_dst(dst, src, sep, *size))
		return (0);
	return (dst);
}
