/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:07:38 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/27 15:01:15 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	dispatcher(char **args, char ***env)
{
	int builtin;

	if (check_args_for_pipes(args))
	{
		if (!ft_strcmp(args[0], "|"))
		{
			parse_error();
			return ;
		}
		sh_pipes_handler(args, env);
	}
	else if (check_args_for_redirs(args))
		handle_redirs_proc(args, env);
	else if ((builtin = check_args_for_builtings(args)) != 10)
		launch_builtin_func(args, builtin, env);
	else
		sh_launch(args, env);
}

void	handle_redirs_proc(char **args, char ***env)
{
	pid_t pid;

	if (!(pid = fork()))
	{
		g_pid = pid;
		sh_launch_redir(args, env);
	}
	wait(NULL);
}
