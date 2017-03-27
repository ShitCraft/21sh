/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:53:52 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 15:04:37 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dup;
	char	*ret;

	if (s && f)
	{
		dup = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!dup)
			return (NULL);
		ret = dup;
		while (*s)
		{
			*dup = (*f)(*s);
			s++;
			dup++;
		}
		*dup = '\0';
		return (ret);
	}
	return (NULL);
}
