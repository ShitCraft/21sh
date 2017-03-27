/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskrypka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:45:53 by oskrypka          #+#    #+#             */
/*   Updated: 2016/12/01 14:55:08 by oskrypka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlst;

	newlst = (t_list *)malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	if (!content)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		newlst->content = ft_memalloc(content_size);
		if (!newlst->content)
			return (NULL);
		newlst->content = ft_memcpy(newlst->content, content, content_size);
		newlst->content_size = content_size;
	}
	newlst->next = NULL;
	return (newlst);
}
