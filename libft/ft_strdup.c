/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:11:09 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 15:02:31 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *dup;

	dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
