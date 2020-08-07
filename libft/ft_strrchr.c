/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:18:42 by lverdoes      #+#    #+#                 */
/*   Updated: 2019/11/26 18:00:39 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return ((char *)s + i);
	return (0);
}
