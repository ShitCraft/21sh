/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:13:55 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/23 14:20:39 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		move_index(int i, char **pipe_args)
{
	while (pipe_args[i] && ft_strcmp(pipe_args[i], "|"))
	{
		if (!pipe_args[i + 1])
			return (i);
		i++;
	}
	return (i);
}
