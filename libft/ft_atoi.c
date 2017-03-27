/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:17:07 by oskrypka          #+#    #+#             */
/*   Updated: 2016/11/29 14:20:46 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int sign;
	int result;

	result = 0;
	while (TAB(*str) || WS(*str))
		str++;
	if ((*str == '-' || *str == '+') && !(*(str + 1) >= 48 && *(str + 1) <= 57))
		return (result);
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	return (result * sign);
}
