/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:03:51 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/23 14:15:02 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char	***split_args(char **line)
{
	char	***res;
	char	**tmp;
	int		size;
	int		i;

	tmp = ft_strsplit(*line, ';');
	size = get_2d_array_len(tmp);
	res = (char ***)malloc(sizeof(char **) * (size + 1));
	i = -1;
	while (tmp[++i])
	{
		res[i] = ft_strsplit(tmp[i], ' ');
//		print_args(res[i]);
	}
	res[i] = NULL;
	free_args(tmp);
	return (res);
}

void	free_3d_array_args(char ***args)
{
	int i;

	i = -1;
	while (args[++i])
		free_args(args[i]);
	free(args);
}
