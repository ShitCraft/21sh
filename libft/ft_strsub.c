/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:50:01 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 15:07:34 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dup;
	char *ret;

	if (s)
	{
		dup = (char *)malloc(sizeof(char) * len + 1);
		if (!dup)
			return (NULL);
		ret = dup;
		if (start)
		{
			s++;
			while (--start)
				s++;
		}
		while (len--)
			*dup++ = *s++;
		*dup = '\0';
		return (ret);
	}
	ret = NULL;
	return (ret);
}
