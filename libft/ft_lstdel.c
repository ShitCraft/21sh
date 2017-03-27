/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:31:48 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 14:53:52 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
		*alst = tmp;
	}
	ft_memdel((void **)alst);
}
