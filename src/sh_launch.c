/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:26:43 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/27 14:52:26 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	sh_launch(char **args, char ***env)
{
    pid_t   pid;
    pid_t   wpid;
    int     status;
    char    *path;

    if (!(pid = fork()))
    {
		g_pid = pid;
        path = get_path(args[0], *env);
        if (!path)
            path = args[0];
        if (execve(path, args, *env) == -1)
        {
            launch_error(args[0]);
            exit(0);
        }
    }
    else
    {
        wpid = waitpid(pid, &status, WUNTRACED);
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
            wpid = waitpid(pid, &status, WUNTRACED);
    }
}
