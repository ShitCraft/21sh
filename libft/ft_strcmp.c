/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:46:39 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 15:01:30 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
