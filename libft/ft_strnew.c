/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:28:52 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 15:06:19 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *dup;
	char *ret;

	dup = (char *)malloc(sizeof(char) * size + 1);
	if (!dup)
		return (NULL);
	ret = dup;
	while (size)
	{
		*dup = '\0';
		dup++;
		size--;
	}
	*dup = '\0';
	return (ret);
}
