/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 11:44:59 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/27 15:00:59 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	sh_launch_pipes(char ***args, char ***env)
{
	int		i;
	int		fd_in;
	int		*p;
	pid_t	pid;
	
	p = (int *)malloc(sizeof(int) * 2);
	fd_in = 0;
	i = 0;
	while (args[i])
	{
		pipe(p);
		if (!(pid = fork()))
		{
			g_pid = pid;
			handle_one_pipe(fd_in, &p, args, i);
			handle_args(args[i], env);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd_in = p[0];
			i++;
		}
	}
}

void	handle_one_pipe(int fd_in, int **pipe, char ***args, int i)
{
	dup2(fd_in, 0);
	if (args[i + 1])
		dup2((*pipe)[1], 1);
	close((*pipe)[0]);
}

void	sh_exec_cmd(char **args, char ***env)
{
	char *path;

	path = get_path(args[0], *env);
	if (!path)
		path = args[0];
	if (execve(path, args, *env) == -1)
	{
		launch_error(args[0]);
		exit(0);
	}
}
