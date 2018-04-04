/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 21:32:46 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 15:56:01 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_lstsort(t_list **begin_list, int (*cmp)(void*, void*))
{
	t_list	*list;
	void	*tmp;

	list = *begin_list;
	if (list)
	{
		while (list->next)
		{
			if (cmp(list->content, list->next->content) > 0)
			{
				tmp = list->next->content;
				list->next->content = list->content;
				list->content = tmp;
				list = *begin_list;
			}
			else
				list = list->next;
		}
	}
}

void		ft_lstadd_back(t_list **begin_list, t_list *new)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*begin_list = new;
}

void		ft_lstadd_front(t_list **begin_list, t_list *new)
{
	t_list	*list;

	if (*begin_list)
	{
		list = new;
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = new;
}

void		ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst)
	{
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}
