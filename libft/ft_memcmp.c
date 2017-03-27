/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:30:04 by oskrypka          #+#    #+#             */
/*   Updated: 2016/11/30 15:04:02 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *tmp1;
	const unsigned char *tmp2;

	tmp2 = s2;
	tmp1 = s1;
	while (n--)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		else
		{
			tmp1++;
			tmp2++;
		}
	}
	return (0);
}
