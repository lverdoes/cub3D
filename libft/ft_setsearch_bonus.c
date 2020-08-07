/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setsearch_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:22:25 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/10 13:37:58 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_setsearch(const char *str, const char *set)
{
	size_t i;
	size_t j;

	if (!str || !set)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
