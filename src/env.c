/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:52:06 by oskrypka          #+#    #+#             */
/*   Updated: 2017/02/27 15:04:32 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getvar(char **env, char *name)
{
	int		i;
	char	*res;

	i = -1;
	while (env[++i])
	{
		if ((ft_strstr(env[i], name)) != NULL)
		{
			res = get_value(env[i]);
			return (res);
		}
	}
	return (NULL);
}

char	*get_value(char *var)
{
	char *res;
	char **tmp;

	tmp = ft_strsplit(var, '=');
	if (tmp[1])
		res = tmp[1];
	else
		res = ft_strnew(0);
	free(tmp[0]);
	free(tmp);
	return (res);
}

char	**get_env(char *envp[])
{
	char	**env;
	char	*tmp;
	int		i;

	env = (char **)malloc(sizeof(char *) * (get_2d_array_len(envp) + 1));
	i = -1;
	while (envp[++i])
		env[i] = ft_strdup(envp[i]);
	env[i] = NULL;
	tmp = get_user_dir(env);
	change_old_dir(&env, tmp);
	free(tmp);
	return (env);
}

int		get_2d_array_len(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}
