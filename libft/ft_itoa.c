/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:42:06 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 14:53:15 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_minint(void)
{
	char	*ret;
	int		i;
	char	*min_int;

	min_int = "-2147483648";
	i = 0;
	ret = (char *)malloc(sizeof(char) * 12);
	if (!ret)
		return (NULL);
	while (min_int[i])
	{
		ret[i] = min_int[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static int		ft_numdefiner(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void		ft_recursion(int n, char *str, int *i)
{
	if (n < 0)
	{
		str[*i] = '-';
		(*i)++;
		n = -n;
	}
	if (n > 9)
	{
		ft_recursion(n / 10, str, i);
		ft_recursion(n % 10, str, i);
	}
	else
	{
		str[*i] = n + '0';
		(*i)++;
	}
}

char			*ft_itoa(int n)
{
	char	*dup;
	char	*ret;
	int		i;

	dup = (char *)malloc(sizeof(char) * (ft_numdefiner(n) + 1));
	if (!dup)
		return (NULL);
	ret = dup;
	if (n == -2147483648)
		return (ft_minint());
	if (!n)
	{
		dup[0] = '0';
		dup[1] = '\0';
	}
	i = 0;
	ft_recursion(n, dup, &i);
	dup[i] = '\0';
	return (ret);
}
