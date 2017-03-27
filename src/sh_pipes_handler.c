/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pipes_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:24:44 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/26 16:37:10 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	sh_pipes_handler(char **pipe_args, char ***env)
{
	int		cmds_num;
	char	***args;

	cmds_num = get_cmds_num(pipe_args);
	args = get_comands(pipe_args, cmds_num);
	sh_launch_pipes(args, env);
}

char	***get_comands(char **pipe_args, int cmds_num)
{
	int		i;
	char	**cmds;
	int		j;
	char	***args;
	int		k;

	args = (char ***)malloc(sizeof(char **) * cmds_num);
	i = 0;
	j = 0;
	while (pipe_args[i])
	{
		cmds = get_one_pipe_args(pipe_args, i);
		if (cmds)
			args[j++] = cmds;
		k = 0;
		while (pipe_args[i] && ft_strcmp(pipe_args[i], "|"))
			i++;
		if (pipe_args[i])
			if (!ft_strcmp(pipe_args[i], "|"))
				i++;
	}
	args[j] = NULL;
	return (args);
}

void	handle_args(char **args, char ***env)
{

	if (check_args_for_redirs(args))
		sh_launch_redir(args, env);
	else
		sh_exec_cmd(args, env);
}
