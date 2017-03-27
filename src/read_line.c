/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:52:41 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/13 14:57:44 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	read_line(int fd, char **line)
{
	int		res;
	char	buf[MAXLINE];
	char	*tmp;

	bzero(buf, sizeof(buf));
	res = read(fd, buf, MAXLINE);
	if (!ft_strlen(buf))
	{
		*line = NULL;
		return ;
	}
	tmp = ft_strchr(buf, '\n');
	*tmp = '\0';
	*line = ft_strdup(buf);
}

char	**create_empty_line(void)
{
	char **res;

	res = (char **)malloc(sizeof(char *));
	res[0] = NULL;
	return (res);
}
