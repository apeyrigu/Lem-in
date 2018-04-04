/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 21:33:07 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 19:51:17 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t		ft_lstsize(t_list *begin_list)
{
	t_list	*list;
	size_t	i;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*temp;
	t_list	*temp2;

	if (!lst || !f)
		return (NULL);
	temp2 = f(lst);
	if ((res = ft_lstnew(temp2->content, temp2->content_size)))
	{
		temp = res;
		lst = lst->next;
		while (lst)
		{
			temp2 = f(lst);
			if (!(temp->next = ft_lstnew(temp2->content, temp2->content_size)))
				return (NULL);
			temp = temp->next;
			lst = lst->next;
		}
	}
	return (res);
}
