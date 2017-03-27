/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:57:05 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/23 14:09:33 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int	check_in_or_out_redir(char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], ">"))
			return (1);
	}
	return (0);
}

int check_redir_params_in(char **args, int flag)
{
	int aux;

	aux = 1;
	if (!flag)
	{
		if (!args[aux] || !args[aux + 1] || !args[aux + 2])
		{
			return (0);
		}
	}
	if (flag)
	{
		if (ft_strcmp(args[aux + 1], ">"))
		{
			input_file_expected_error(args[aux + 1]);
			return (0);
		}
	}
	return (1);
}

int		check_redir_params_out(char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], ">"))
			break;
	}
	if (!args[i + 1])
	{
		output_file_expected_error();
		return (0);
	}
	return (1);
}
