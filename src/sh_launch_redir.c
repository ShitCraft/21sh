/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:40:42 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/26 16:38:29 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	sh_launch_redir(char **args, char ***env)
{
	if (check_in_or_out_redir(args))
	{
		if (!check_redir_params_out(args))
			return ;
		else
		{
			do_redir_shit(args, OUT, env);
			return ;
		}
	}
	if (!check_redir_params_in(args, 0))
		return ;
	if (!check_redir_params_in(args, 1))
		return ;
	do_redir_shit(args, IN, env);
}

void	do_redir_shit(char **args, int flag, char ***env)
{
	int		fd;
	char	**exec;
	int		builtin;
	char	*file;

	file = get_redir_file(args);
	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec = get_args_before_redir(args);
	if ((builtin = check_args_for_builtings(args)) != 10)
		launch_builtin_func(exec, builtin, env);
	else
		sh_exec_cmd(exec, env);
	free(file);
}

char	*get_redir_file(char **args)
{
	int		i;
	char	*file;

	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], ">") ||
			!ft_strcmp(args[i], "<"))
		{
			return ((file = ft_strdup(args[i + 1])));
		}
	}
	return (NULL);
}

char	**get_args_before_redir(char **args)
{
	char	**arg;
	int		i;

	i = get_size_before_redir(args);
	arg = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], ">") || 
			!ft_strcmp(args[i], "<"))
		{
			arg[i] = NULL;
			break ;
		}
		arg[i] = ft_strdup(args[i]);
	}
	return (arg);
}
