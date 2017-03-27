/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:12:24 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/22 11:02:18 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_home_dir(char ***env)
{
	char	*tmp;
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	tmp = get_user_dir(*env);
	chdir(tmp);
	change_old_dir(env, cwd);
	free(tmp);
}

void	cd_prev_dir(char ***env)
{
	char	*tmp;
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	tmp = get_prev_dir(*env);
	ft_putstr("\n");
	ft_putstr(tmp);
	chdir(tmp);
	change_old_dir(env, cwd);
	free(tmp);
}

void	cd_error(char *dir)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

char	*get_dir(char *path, char **env)
{
	char *res;
	char *tmp;
	char *tmp2;

	res = get_user_dir(env);
	tmp = ft_strchr(path, '~');
	tmp2 = ft_strjoin(res, ++tmp);
	free(res);
	res = tmp2;
	return (res);
}
