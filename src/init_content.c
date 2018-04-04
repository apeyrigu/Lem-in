/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 06:22:56 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/28 02:19:26 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_res			*create_node(size_t *content, size_t tab_size)
{
	t_res		*res;

	res = ft_memalloc(sizeof(t_res));
	res->content = content;
	res->tab_size = tab_size;
	return (res);
}

void			ft_lstadd_back_res(t_res **begin_list,
				size_t *content, size_t tab_size)
{
	t_res		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = create_node(content, tab_size);
	}
	else
		*begin_list = create_node(content, tab_size);
}
