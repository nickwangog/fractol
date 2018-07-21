/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:07:43 by nwang             #+#    #+#             */
/*   Updated: 2017/10/03 15:49:31 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *new_elem;
	t_list *prev_elem;

	new_lst = NULL;
	if (lst && (*f))
	{
		new_lst = (*f)(lst);
		prev_elem = new_lst;
		lst = lst->next;
		while (lst)
		{
			new_elem = (*f)(lst);
			prev_elem->next = new_elem;
			prev_elem = new_elem;
			lst = lst->next;
		}
		prev_elem->next = NULL;
	}
	return (new_lst);
}
