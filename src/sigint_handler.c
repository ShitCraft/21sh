/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:48:59 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/27 15:12:08 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	sigint_handler(int sig)
{
	if (g_pid)
	{
		kill(g_pid, SIGKILL);
		g_pid = 0;
	}
	signal(SIGINT, sigint_handler);
}
