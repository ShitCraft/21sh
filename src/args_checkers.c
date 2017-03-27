/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:24:50 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/24 14:01:00 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		check_args_for_pipes(char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], "|"))
			return (1);
	}
	return (0);
}

int		check_args_for_redirs(char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], "<") || !ft_strcmp(args[i], ">"))
			return (1);
	}
	return (0);
}

int		check_args_for_builtings(char **args)
{
	if (!ft_strcmp(args[0], "cd"))
		return (CD);
	else if (!ft_strcmp(args[0], "help"))
		return (HELP);
	else if (!ft_strcmp(args[0], "echo"))
		return (ECHO);
	else if (!ft_strcmp(args[0], "env"))
		return (ENV);
	else if (!ft_strcmp(args[0], "exit"))
		return (EXIT);
	else if (!ft_strcmp(args[0], "setenv"))
		return (SETENV);
	else if (!ft_strcmp(args[0], "unsetenv"))
		return (UNSETENV);
	else
		return (10);
}
