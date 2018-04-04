/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 21:32:32 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 20:55:18 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void			ft_lstclear_n(t_list **begin_list)
{
	t_list		*list;

	if (*begin_list)
	{
		list = *begin_list;
		*begin_list = (*begin_list)->next;
		ft_free(PARSE_N(list));
		ft_free(list->content);
		ft_free(list);
	}
}

void			ft_lstremove_if_p(t_list **begin_list, void *data_ref1,
				void *data_ref2, int (*cmp)())
{
	t_list		*list;

	if (*begin_list)
	{
		if (!cmp(((t_parser *)(*begin_list)->content)->key,
			data_ref1, data_ref2, cmp_pars))
		{
			list = *begin_list;
			*begin_list = (*begin_list)->next;
			ft_free(PARSE_N(list));
			ft_free(list->content);
			ft_free(list);
			ft_lstremove_if_p(begin_list, data_ref1, data_ref2, cmp);
		}
		else
			ft_lstremove_if_p((t_list **)&(*begin_list)->next,
			data_ref1, data_ref2, cmp);
	}
}

void			ft_lstremove_if(t_list **begin_list, void *data_ref,
				int (*cmp)())
{
	t_list		*list;

	if (*begin_list)
	{
		if (!cmp((*begin_list)->content, data_ref))
		{
			list = *begin_list;
			*begin_list = (*begin_list)->next;
			ft_free(list);
			ft_lstremove_if(begin_list, data_ref, cmp);
		}
		else
			ft_lstremove_if(&(*begin_list)->next, data_ref, cmp);
	}
}

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		**tmp;
	t_list		*tmpnext;

	tmp = alst;
	while (*tmp != NULL)
	{
		tmpnext = (*tmp)->next;
		del((*tmp)->content, (*tmp)->content_size);
		ft_free(*tmp);
		*tmp = tmpnext;
	}
}
