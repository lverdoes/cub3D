/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 10:43:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2019/11/11 17:16:24 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = len1 + ft_strlen(s2);
	str = malloc(len2 + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcat(str, s2, len2 + 1);
	return (str);
}
