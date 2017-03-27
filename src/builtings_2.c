/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:57:46 by oskrypka          #+#    #+#             */
/*   Updated: 2017/02/27 12:13:36 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_env(char *arg, char ***env)
{
	int		i;
	char	*tmp;
	char	*val;

	if (arg[0] == '"' && arg[ft_strlen(arg) - 1] == '"')
	{
		tmp = &arg[1];
		arg[ft_strlen(arg) - 1] = '\0';
	}
	else
		tmp = arg;
	i = -1;
	while ((*env)[++i] && tmp[0] == '$')
	{
		if ((ft_strstr((*env)[i], &tmp[1])) != NULL)
		{
			val = getvar(*env, &tmp[1]);
			ft_putstr_wq(val);
			free(val);
			return ;
		}
	}
	ft_putstr_wq(tmp);
}

void	ft_putstr_wq(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '"')
			write(1, &str[i], 1);
	}
}
