/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 05:44:02 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/28 23:54:27 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

bool		check(size_t *tmp, size_t len, size_t i)
{
	size_t	j;

	j = 0;
	while (j != len)
	{
		if (tmp[j] == i)
			return (true);
		j++;
	}
	return (false);
}

size_t		ft_found_len(t_lem *lm, size_t *tmp, size_t len, size_t i)
{
	size_t	k;
	size_t	found;
	bool	key;
	size_t	j;

	found = 0;
	k = len;
	while (i != len)
	{
		j = i + 1;
		key = false;
		while (j++ != len && key == false)
		{
			if (tmp[j] == tmp[i])
			{
				k--;
				key = true;
			}
		}
		ft_comp_tab(lm, tmp[i]) == false &&
		check(tmp, i, tmp[i]) == false ? found++ : (void)i;
		i++;
	}
	k = k - found;
	return (k);
}

void		ft_view_double(t_lem *lm, size_t *tmp, size_t len, size_t i)
{
	size_t	*tab;
	size_t	len2;
	size_t	mini;
	size_t	j;

	j = 0;
	mini = 1;
	len2 = ft_found_len(lm, tmp, len, 0);
	if ((int)len2 < 1)
		ft_error_pars(0);
	tab = ft_memalloc(sizeof(size_t) * len2);
	while (i != len)
	{
		while (tab[j] != tmp[i] && j != mini)
			j++;
		if (j == mini && ft_comp_tab(lm, tmp[i]) == true)
		{
			tab[mini - 1] = tmp[i];
			mini += 1;
		}
		j = 0;
		i++;
	}
	lm->size = len2;
	ft_lstadd_back_res(&lm->tab, tab, len2);
}

size_t		*ft_make(t_res *check, t_lem *lm, size_t len, size_t *tmp)
{
	t_list	*room;
	t_list	*link;

	room = lm->room;
	while (room)
	{
		while (lm->i != check->tab_size)
		{
			if (check->content[lm->i++] == ((t_room*)room->content)->nb_name)
			{
				link = ((t_room*)room->content)->link;
				while (link)
				{
					tmp[lm->j] = ((t_link*)link->content)->nb_name;
					link = link->next;
					lm->j++;
					if (lm->j == len)
						return (tmp);
				}
			}
		}
		lm->i = 0;
		room = room->next;
	}
	return (tmp);
}

void		ft_make_line(t_res *check, t_lem *lm, size_t len)
{
	size_t	*tmp;

	lm->j = 0;
	lm->i = 0;
	tmp = ft_make(check, lm, len, (size_t *)ft_memalloc(sizeof(size_t) * len));
	ft_view_double(lm, tmp, len, 0);
	ft_memdel((void *)&tmp);
}
