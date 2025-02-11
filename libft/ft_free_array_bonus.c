/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 13:42:00 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/06/10 13:47:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_array(void **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}
