/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <oskrypka@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:53:28 by oskrypka          #+#    #+#             */
/*   Updated: 2017/03/23 13:31:50 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	input_file_expected_error(char *arg)
{
	ft_putstr("Usage: Expected '>' and found ");
	ft_putstr(arg);
	ft_putendl("");
}

void	input_args_error(void)
{
	ft_putendl("Not enough input arguments!");
}

void	output_file_expected_error(void)
{
	ft_putendl("Not enough output arguments!");
}

void	parse_error(void)
{
	ft_putendl("parse error near `|'");
}
