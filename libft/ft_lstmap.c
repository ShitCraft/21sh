/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:01:09 by oskrypka          #+#    #+#             */
/*   Updated: 2016/11/29 12:51:13 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *newlst;
	t_list *carriage;

	if (!lst || !f)
		return (NULL);
	newlst = (*f)(lst);
	if (!newlst)
		return (NULL);
	ret = newlst;
	carriage = lst->next;
	while (carriage)
	{
		newlst->next = (*f)(carriage);
		newlst = newlst->next;
		if (!newlst)
			return (NULL);
		carriage = carriage->next;
	}
	return (ret);
}
