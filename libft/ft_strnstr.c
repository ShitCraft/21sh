/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:14:36 by oskrypka          #+#    #+#             */
/*   Updated: 2016/11/29 11:30:42 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;

	if (!*big || len < 1)
		return (NULL);
	i = ft_strlen(little);
	while (len-- >= i)
	{
		if (!ft_memcmp(big++, little, i))
			return ((char *)(big - 1));
	}
	return (0);
}
