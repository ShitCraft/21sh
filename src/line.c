/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:41:21 by oskrypka          #+#    #+#             */
/*   Updated: 2017/02/27 15:04:56 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!WS(line[i]))
			return (1);
	}
	return (0);
}

void	launch_error(char *prog)
{
	ft_putstr_fd("No command '", 2);
	ft_putstr_fd(prog, 2);
	ft_putendl_fd("' found", 2);
}
