/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:56:59 by oskrypka          #+#    #+#             */
/*   Updated: 2016/11/29 13:27:06 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_d;
	const char	*tmp_s;
	int			i;

	i = 0;
	tmp_d = dst;
	tmp_s = src;
	if (dst < src)
	{
		while (len--)
		{
			tmp_d[i] = tmp_s[i];
			i++;
		}
	}
	else
	{
		tmp_d = dst + (len - 1);
		tmp_s = src + (len - 1);
		while (len--)
			*tmp_d-- = *tmp_s--;
	}
	return (dst);
}
