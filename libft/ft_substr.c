/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 09:38:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2019/11/21 16:47:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			n;

	if (!s)
		return (0);
	n = ft_strlen(s);
	if (n - start < len)
		len = n - start;
	substr = malloc(len + 1);
	if (!substr)
		return (0);
	i = 0;
	while (i < len && start < n)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
