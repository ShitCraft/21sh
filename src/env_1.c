/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:30:37 by oskrypka          #+#    #+#             */
/*   Updated: 2017/02/27 13:20:23 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rewr_envvar(char ***env, int i, char *value)
{
	char	**tmp;
	char	*res;
	int		val;

	val = 0;
	if (value)
		val = ft_strlen(value);
	tmp = ft_strsplit((*env)[i], '=');
	res = ft_strnew(ft_strlen(tmp[0]) + val + 1);
	res = ft_strcpy(res, tmp[0]);
	res = ft_strcat(res, "=");
	if (val)
		res = ft_strcat(res, value);
	free((*env)[i]);
	(*env)[i] = res;
	free_args(tmp);
}

void	add_envvar(char ***env, char *key, char *value)
{
	int		size;
	char	*var;
	int		i;
	char	**new_env;
	int		val;

	val = 0;
	if (value)
		val = ft_strlen(value);
	size = get_2d_array_len((*env)) + 2;
	new_env = (char **)malloc(sizeof(char *) * size);
	i = -1;
	while ((*env)[++i])
		new_env[i] = (*env)[i];
	new_env[i] = ft_strnew(ft_strlen(key) + val + 1);
	new_env[i] = ft_strcat(new_env[i], key);
	new_env[i] = ft_strcat(new_env[i], "=");
	if (val)
		new_env[i] = ft_strcat(new_env[i], value);
	new_env[++i] = NULL;
	free(*env);
	(*env) = new_env;
}

void	unset_envvar(char ***env, int i, char *var)
{
	int		j;
	int		k;
	char	**new_env;
	int		size;

	size = get_2d_array_len((*env)) + 1;
	new_env = (char **)malloc(sizeof(char *) * size);
	free((*env)[i]);
	(*env)[i] = NULL;
	j = -1;
	while ((*env)[++j])
		new_env[j] = (*env)[j];
	if ((*env)[j + 1])
	{
		k = j + 1;
		while ((*env)[k])
			new_env[j++] = (*env)[k++];
		free((*env)[++k]);
		new_env[j] = NULL;
	}
	free(*env);
	(*env) = new_env;
}

char	*get_prev_dir(char **env)
{
	char *tmp;

	tmp = getvar(env, "OLDPWD");
	return (tmp);
}
