/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:38:37 by oskrypka          #+#    #+#             */
/*   Updated: 2017/02/23 18:11:13 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_old_dir(char ***env, char *dir)
{
	int		i;
	char	*tmp;

	i = -1;
	while ((*env)[++i])
	{
		if ((ft_strstr((*env)[i], "OLDPWD")) != NULL)
		{
			free((*env)[i]);
			(*env)[i] = ft_strdup("OLDPWD=");
			tmp = ft_strjoin((*env)[i], dir);
			free((*env)[i]);
			(*env)[i] = tmp;
			return ;
		}
	}
}
