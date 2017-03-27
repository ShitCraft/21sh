/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:39:04 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/27 12:39:07 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	add_char_to_line(char ch)
{
	char *tmp;
	char *tmp2;

	tmp = ft_memalloc(2);
	tmp[0] = ch;
	tmp[1] = '\0';
	tmp2 = ft_strjoin(g_input->line, tmp);
	free(g_input->line);
	g_input->line = tmp2;
	g_input->pos++;
	g_input->len++;
	free(tmp);
}

void	insert_char(char ch)
{
	char *offset;
	int len;
	int i;

	i = -1;
	len = g_input->len - g_input->pos;
	offset = get_offset();
	insert_char_in_line(offset, ch);
	while (++i < len)
		tputs(tgetstr("dc", NULL), 0, myputchar);
	write(1, &ch, 1);
	g_input->len += 1;
	g_input->pos += 1;
	ft_putstr(offset);
	free(offset);
	i = -1;
	while (++i < len)
		tputs(tgetstr("le", NULL), 0, myputchar);
}

char	*get_offset(void)
{
	char *res;
	int i;

	i = g_input->pos;
	res = ft_strdup(&(g_input->line[i]));
	return (res);
}

void	remove_one_char(void)
{
	int len;

	if (check_pos(0))
	{
		g_input->len -= 1;
		delete_char_in_line();
		kl_event();
		tputs(tgetstr("dc", NULL), 0, myputchar);
	}
}

int	check_pos(int direction)
{
	if (!direction) /* checks in left direction */
	{
		if (g_input->pos > 0)
			return (1);
		else
			return (0);
	}
	else /* checks in right direction */
	{
		if (g_input->pos < g_input->len)
			return (1);
		else
			return (0);
	}
}
