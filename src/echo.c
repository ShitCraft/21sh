/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:18:40 by oskrypka          #+#    #+#             */
/*   Updated: 2017/02/27 12:24:15 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wfl_echo(char **args, char ***env)
{
	int i;

	i = 1;
	while (args[++i])
		check_env(args[i], env);
	ft_putstr("%\n");
}

void	echo(char **args, char ***env)
{
	int	i;

	i = 0;
	while (args[++i])
	{
		check_env(args[i], env);
		ft_putstr(" ");
	}
	ft_putstr("\n");
}
