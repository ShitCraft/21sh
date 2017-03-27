/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:48:42 by oskrypka          #+#    #+#             */
/*   Updated: 2016/11/30 14:36:02 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s) + 1;
	while (--len >= -1)
	{
		if (s[len] == c)
			return (char *)&s[len];
	}
	return (0);
}
