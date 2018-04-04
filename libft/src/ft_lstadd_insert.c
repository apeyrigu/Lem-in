/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 06:24:34 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/27 17:04:44 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	get_pos_add(t_list *list, t_list *new,
				int (*cmp)(void *, void *))
{
	size_t		res;

	res = 0;
	while (list)
	{
		if (cmp(list, new) >= 0)
			break ;
		list = list->next;
		res++;
	}
	return (res);
}

static void		ft_lstadd_index2(t_list **begin_list, t_list *new, t_list *list)
{
	list = new;
	list->next = NULL;
	*begin_list = list;
}

static void		ft_lstadd_index1(t_list **begin_list, t_list *new, t_list *list)
{
	list = new;
	list->next = *begin_list;
	*begin_list = list;
}

void			ft_lstadd_index(t_list **begin_list, t_list *new,
				int (*cmp)(void *, void *), size_t i)
{
	t_list		*list;
	t_list		*tmp;
	size_t		len;

	list = *begin_list;
	len = D_LIST(size)(list);
	if (list)
	{
		i = get_pos_add(list, new, cmp);
		if (i == 0)
		{
			ft_lstadd_index1(begin_list, new, list);
			return ;
		}
		while (i--)
		{
			tmp = list;
			list = list->next;
		}
		tmp->next = new;
		tmp->next->next = list;
	}
	else
		ft_lstadd_index2(begin_list, new, list);
}
