/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:58:14 by oskrypka          #+#    #+#             */
/*   Updated: 2017/02/23 16:54:28 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int	getcwd_len(void)
{
	int res;
	char cwd[1024];
	char *handled_cwd;

	getcwd(cwd, sizeof(cwd));
	handled_cwd = handle_cwd(cwd, environ);
	if (!(handled_cwd[0] == '/' && !handled_cwd[1]))
		res = ft_strlen(handled_cwd) + 3;
	else
		res = ft_strlen(handled_cwd) + 2;
	free(handled_cwd);
	return (res);
}

void	print_curr_dir(char **env)
{
	char cwd[1024];
	char *handled_cwd;

	getcwd(cwd, sizeof(cwd));
	handled_cwd = handle_cwd(cwd, env);
	ft_putstr(handled_cwd);
	if (!(handled_cwd[0] == '/' && !handled_cwd[1]))
		ft_putstr("/> ");
	else
		ft_putstr("> ");
	if (handled_cwd)
		free(handled_cwd);
}

char	*handle_cwd(char *cwd, char **env)
{
	char *res;
	char *user_dir;
	char *tmp;
	char *tmp2;

	user_dir = get_user_dir(env);
	if ((tmp = ft_strstr(cwd, user_dir)) != NULL)
	{
		res = ft_strdup("~");
		if ((tmp = after_user_dir(cwd, user_dir)) != NULL)
		{
			tmp2 = ft_strjoin(res, tmp);
			free(res);
			free(tmp);
			res = tmp2;
		}
		free(user_dir);
		return (res);
	}
	else
		res = ft_strdup(cwd);
	if (user_dir)
		free(user_dir);
	return (res);
}

char	*after_user_dir(char *cwd, char *user_dir)
{
	char	*res;
	char	*after;
	int		i;

	i = 0 + ft_strlen(user_dir);
	after = ft_memalloc(ft_strlen(&cwd[i]) + 1);
	after = ft_strcpy(after, &cwd[i]);
	return (after);
}

char	*get_user_dir(char **env)
{
	char *tmp;

	tmp = getvar(env, "HOME");
	return (tmp);
}
