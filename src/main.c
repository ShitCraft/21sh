/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:56:36 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/27 15:05:33 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		main(int ac, char **av, char *envp[])
{
	signal(SIGINT, sigint_handler);
	sh_loop(envp);
	return (0);
}

void	sh_loop(char *envp[])
{
	char	*line;
	char	**env;
	char	***av;
	int		i;

	if (!get_entry())
		exit(0);
	env = get_env(envp);
	create_input();
	while (1)
	{
		print_curr_dir(env);
		handle_input();
		add_command_to_list(&g_list, g_input->line);
		av = split_args(&g_input->line);
		i = -1;
		while (av[++i])
			dispatcher(av[i], &env);
		refresh_input();
		free_3d_array_args(av);
	}
	free_args(env);
}
