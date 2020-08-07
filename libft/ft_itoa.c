/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 08:53:21 by lverdoes      #+#    #+#                 */
/*   Updated: 2019/11/11 16:53:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(char *str, int i, int n)
{
	if (n >= 10)
		putnbr(str, i - 1, n / 10);
	str[i] = n % 10 + 48;
}

static int	find_len(int n)
{
	int len;

	if (n == -2147483648)
		return (11);
	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = find_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == -2147483648)
	{
		str[10] = '8';
		n = -214748364;
		len--;
	}
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	putnbr(str, len - 1, n);
	return (str);
}
