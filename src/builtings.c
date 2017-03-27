/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:55:46 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/24 14:11:38 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	launch_builtin_func(char **args, int i, char ***env)
{
	t_builtin	func;

	func = (t_builtin)malloc(sizeof(t_builtin));
	if (i == CD)
		func = sh_cd;
	else if (i == HELP)
		func = sh_help;
	else if (i == EXIT)
		func = sh_exit;
	else if (i == ENV)
		func = sh_env;
	else if (i == ECHO)
		func = sh_echo;
	else if (i == SETENV)
		func = sh_setenv;
	else if (i == UNSETENV)
		func = sh_unsetenv;
	func(args, env);
//	free(func);
}

char		**get_func_names(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (BUILT_NUM + 1));
	res[CD] = ft_strdup("cd");
	res[HELP] = ft_strdup("help");
	res[ECHO] = ft_strdup("echo");
	res[ENV] = ft_strdup("env");
	res[EXIT] = ft_strdup("exit");
	res[SETENV] = ft_strdup("setenv");
	res[UNSETENV] = ft_strdup("unsetenv");
	res[BUILT_NUM] = NULL;
	return (res);
}

int			sh_help(char **args, char ***env)
{
	int		i;
	char	**builtings;

	ft_putendl("Alexii Skrypka's Minishell");
	ft_putstr("Type program names and arguments");
	ft_putendl(" and hit fucking enter!");
	ft_putendl("The following are buitings in:");
	builtings = get_func_names();
	i = -1;
	while (builtings[++i])
	{
		ft_putstr("[");
		ft_putstr(builtings[i]);
		ft_putendl("]");
	}
	ft_putstr("Use the man command for information on");
	ft_putendl(" other programs.");
	free(builtings);
	return (1);
}

int			sh_exit(char **args, char ***env)
{
	exit(0);
	return (0);
}

int			sh_cd(char **args, char ***env)
{
	char cwd[1024];
	char *tmp;

	getcwd(cwd, sizeof(cwd));
	if (!args[1])
		cd_home_dir(env);
	else if (args[1][0] == '-' && !args[1][1])
		cd_prev_dir(env);
	else
	{
		tmp = ft_strdup(args[1]);
		if (ft_strchr(args[1], '~'))
		{
			free(tmp);
			tmp = get_dir(args[1], *env);
		}
		if (chdir(tmp))
			cd_error(tmp);
		else
			change_old_dir(env, cwd);
		free(tmp);
	}
	return (1);
}
