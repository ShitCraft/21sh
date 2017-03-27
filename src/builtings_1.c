/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:11:26 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/24 14:04:08 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		sh_echo(char **args, char ***env)
{
	if (!args[1])
	{
		ft_putstr("\n");
		return (1);
	}
	if (args[1][0] == '-' && args[1][1] == 'n' && !args[1][2])
	{
		if (!args[2])
			return (1);
		wfl_echo(args, env);
	}
	else
		echo(args, env);
	return (1);
}

int		sh_env(char **args, char ***env)
{
	int	i;

	i = -1;
	while ((*env)[++i])
		ft_putendl((*env)[i]);
	return (1);
}

int		sh_setenv(char **args, char ***env)
{
	int	i;

	if (!args[1])
	{
		sh_env(args, env);
		return (1);
	}
	i = -1;
	while ((*env)[++i])
	{
		if ((ft_strstr((*env)[i], args[1])) != NULL)
		{
			if (args[2])
				rewr_envvar(env, i, args[2]);
			else
				rewr_envvar(env, i, NULL);
			return (1);
		}
	}
	if (args[2])
		add_envvar(env, args[1], args[2]);
	else
		add_envvar(env, args[1], NULL);
	return (1);
}

int		sh_unsetenv(char **args, char ***env)
{
	int i;

	if (!args[1])
		return (1);
	i = -1;
	while ((*env)[++i])
	{
		if ((ft_strstr((*env)[i], args[1])) != NULL)
		{
			unset_envvar(env, i, args[1]);
			return (1);
		}
	}
	return (1);
}
