/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:37:55 by oskrypka          #+#    #+#             */
/*   Updated: 2016/11/29 13:31:26 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	while (n--)
		if ((*d++ = *s++) == c)
			return (d);
	return (NULL);
}
