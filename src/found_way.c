/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 10:03:34 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/28 02:18:41 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		ft_found_next_link(t_lem *lm, size_t len, t_res *line, t_list *tmp)
{
	size_t	j;
	t_list	*link;

	j = lm->size - len;
	while (((t_room *)tmp->content)->nb_name != lm->final[len - 1])
		tmp = tmp->next;
	link = ((t_room *)tmp->content)->link;
	while (--j != 0)
		line = line->next;
	while (link)
	{
		while (j != line->tab_size)
		{
			if (((t_link *)link->content)->nb_name == line->content[j])
			{
				lm->final[len] = ((t_link *)link->content)->nb_name;
				return ;
			}
			j++;
		}
		j = 0;
		link = link->next;
	}
}

size_t		ft_len_way(t_res *link, t_lem *lm)
{
	size_t	i;

	i = 0;
	while (link)
	{
		link = link->next;
		i++;
	}
	lm->final = ft_memalloc(sizeof(size_t) * i);
	return (i);
}

void		ft_found_way(t_lem *lm, t_res *tab)
{
	size_t	size;
	size_t	j;

	size = ft_len_way(tab, lm);
	lm->size = size;
	while (size != 0)
	{
		j = size - 1;
		while (j != 0)
		{
			tab = tab->next;
			j--;
		}
		if (tab->content[0] == lm->over)
		{
			lm->final[0] = tab->content[0];
			tab = lm->tab;
			size--;
			continue ;
		}
		ft_found_next_link(lm, lm->size - size, lm->tab, lm->room);
		size--;
		tab = lm->tab;
	}
}
