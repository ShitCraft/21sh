/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:07:42 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/26 15:13:39 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int get_size_before_redir(char **args)
{
    int i;

    i = -1;
    while (args[++i])
    {
        if (!(ft_strcmp(args[i], ">")) ||
            !(ft_strcmp(args[i], "<")))
            return (i);
    }
    return (i);
}

char	**get_memory_for_args(char **pipe_args, int i)
{
	char **args;

	while (pipe_args[i] && ft_strcmp(pipe_args[i], "|"))
		i++;
	args = (char **)malloc(sizeof(char *) * (i + 1));
	return (args);
}

char	**get_one_pipe_args(char **pipe_args, int i)
{
	int		j;
	char	**args;

	args = get_memory_for_args(pipe_args, i);
	j = -1;
	while (pipe_args[i] && ft_strcmp(pipe_args[i], "|"))
		args[++j] = ft_strdup(pipe_args[i++]);
	args[++j] = NULL;
	return (args);
}

int	get_cmds_num(char **pipe_args)
{
	int i;
	int res;

	res = 1;
	i = -1;
	while (pipe_args[++i])
	{
		if (!ft_strcmp(pipe_args[i], "|"))
			res++;
	}
	return (res);
}

void	free_args(char **args)
{
	int i;
	int j;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}
