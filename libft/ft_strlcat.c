/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:15:49 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 15:03:54 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	n;
	char	*d;
	char	*s;

	d = dst;
	s = (char *)src;
	n = size;
	while (n-- && *d)
		d++;
	d_len = d - dst;
	n = size - d_len;
	if (!n)
		return (d_len + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (d_len + (s - src));
}
