/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:43:26 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/13 13:43:07 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int	myputchar(int ch)
{
	write(1, &ch, 1);
	return (1);
}

void	kup_event(void)
{
	move_through_list_up(&g_list);
}

void	kd_event(void)
{
	move_through_list_down(&g_list);
}

void	bs_event(void)
{
	remove_one_char();
}

void	cl_event(void)
{
	tputs(tgetstr("cl", NULL), 0, myputchar);
}
