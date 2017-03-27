/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:30:28 by oskrypka          #+#    #+#             */
/*   Updated: 2017/02/22 17:47:54 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_crutch(int i, int len, char **dup, char *start)
{
	while (i <= len)
		(*dup)[i++] = *start++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*dup;
	char	*start;
	int		len;
	char	*end;
	int		i;

	if (!s)
		return (NULL);
	while (WS(*s))
		s++;
	len = ft_strlen(s);
	start = (char *)s;
	while (*s)
		s++;
	s--;
	while (WS(*s))
		s--;
	end = (char *)s;
	len -= ft_strlen(end);
	if (!(dup = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	i = 0;
	i = ft_crutch(i, len, &dup, start);
	dup[i] = '\0';
	return (dup);
}
