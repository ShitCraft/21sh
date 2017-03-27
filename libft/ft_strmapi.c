/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:05:13 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 15:04:52 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dup;
	char			*ret;

	if (s && f)
	{
		i = 0;
		dup = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!dup)
			return (NULL);
		ret = dup;
		while (*s)
		{
			*dup = (*f)(i, *s);
			s++;
			dup++;
			i++;
		}
		*dup = '\0';
		return (ret);
	}
	ret = NULL;
	return (ret);
}
