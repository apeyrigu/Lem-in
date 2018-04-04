/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 11:22:07 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/28 02:04:25 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

size_t			ft_double(t_room *tmp, t_lem *lm, size_t i, t_res *tab)
{
	t_list		*link;
	size_t		value;

	(void)lm;
	value = tmp->nb_link;
	link = tmp->link;
	while (link)
	{
		while (i != tmp->nb_link)
		{
			if (((t_link *)link->content)->nb_name == tab->content[i])
			{
				value--;
			}
			i++;
		}
		link = link->next;
	}
	return (value);
}

size_t			ft_found_nb_link(t_res *check, t_lem *lm)
{
	t_list		*tmp;
	size_t		value;
	size_t		i;

	i = 0;
	value = 0;
	tmp = lm->room;
	while (tmp)
	{
		while (i != check->tab_size && i < check->tab_size)
		{
			if (check->content[i] == ((t_room*)tmp->content)->nb_name)
			{
				value += ft_double(tmp->content, lm, 0, check);
			}
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
	return (value);
}

t_res			*ft_new_line(t_lem *lm)
{
	t_res		*check;
	size_t		len;

	check = lm->tab;
	while (check->next)
		check = check->next;
	len = ft_found_nb_link(check, lm);
	ft_make_line(check, lm, len);
	return (check);
}

void			ft_found_end(size_t **tab, size_t end, size_t len)
{
	size_t		i;
	size_t		s;
	size_t		*tmp;

	i = 0;
	tmp = *tab;
	while (i != len)
	{
		if (tmp[i] == end)
		{
			s = tmp[0];
			tmp[0] = end;
			tmp[i] = s;
			return ;
		}
		i++;
	}
}

void			ft_table_create(t_lem *lm, size_t *temp,
				t_res *check)
{
	t_list		*tmp;

	tmp = lm->room;
	while (tmp)
	{
		if (ft_strcmp(((t_room *)tmp->content)->name, lm->start) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
	{
		temp = ft_memalloc(sizeof(size_t) * 2);
		temp[0] = ((t_room*)tmp->content)->nb_name;
		ft_lstadd_back_res(&lm->tab, temp, 0);
		check = lm->tab;
		check->tab_size = 1;
		while (check->content[0] != lm->over)
		{
			ft_new_line(lm);
			check = check->next;
			check->tab_size = lm->size;
			ft_found_end(&check->content, lm->over, lm->size);
		}
	}
}
