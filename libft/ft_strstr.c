/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:53:37 by oskrypka          #+#    #+#             */
/*   Updated: 2016/11/29 13:33:12 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int big_len;
	int little_len;

	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (!little_len)
		return ((char *)big);
	while (big_len-- >= little_len)
	{
		if (!ft_memcmp(big, little, little_len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
