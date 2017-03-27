/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:02:24 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 15:38:24 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*dup;
	int		i;
	int		j;

	if (s1 && s2)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		i = i + j;
		dup = (char *)malloc(sizeof(char) * i + 1);
		if (!dup)
			return (NULL);
		ret = dup;
		while (*s1)
			*dup++ = *s1++;
		while (*s2)
			*dup++ = *s2++;
		*dup = '\0';
		return (ret);
	}
	return (NULL);
}
