/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:57:08 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/23 13:45:47 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char	*get_path(char *name, char **env)
{
	int		i;
	char	*res;
	char	*tmp;
	char	**folds;
	char	*path;

	path = getvar(env, "PATH");
	if (!path)
		return (NULL);
	folds = ft_strsplit(path, ':');
	if (!folds)
		return (NULL);
	i = -1;
	while (folds[++i])
	{
		res = get_abs_path(folds[i], name);
		if (!access(res, F_OK))
			return (res);
		free(res);
	}
	return (NULL);
}

char	*get_abs_path(char *fold, char *name)
{
	char *res;
	char *tmp;

	res = ft_memalloc(sizeof(fold) + sizeof(name) + 2);
	res = ft_strcpy(res, fold);
	tmp = ft_strjoin(res, "/");
	free(res);
	res = tmp;
	tmp = ft_strjoin(res, name);
	free(res);
	res = tmp;
	return (res);
}
