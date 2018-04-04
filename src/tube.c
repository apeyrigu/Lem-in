/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 04:45:50 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/28 01:52:51 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static t_link	*link_node(char *room, size_t key)
{
	t_link		*res;

	res = ft_memalloc(sizeof(t_link));
	res->name = ft_strdup(room);
	res->nb_name = key;
	return (res);
}

static size_t	get_nb_room(t_lem *lm, char *room)
{
	t_list		*tmp;

	tmp = lm->room;
	while (tmp)
	{
		if (ft_strcmp(((t_room *)tmp->content)->name, room) == 0)
			return (((t_room *)tmp->content)->nb_name);
		tmp = tmp->next;
	}
	return (0);
}

void			ft_create_tube(t_lem *lm, char *room, char *room1)
{
	t_list		*tmp;
	void		*node;

	node = NULL;
	tmp = lm->room;
	while (tmp)
	{
		if (ft_strcmp(((t_room*)tmp->content)->name, room) == 0)
		{
			node = link_node(room1, get_nb_room(lm, room1));
			ft_lstadd(&((t_room *)tmp->content)->link,
			ft_lstnew(node, sizeof(t_link)));
			ft_memdel((void *)&node);
		}
		if (ft_strcmp(((t_room*)tmp->content)->name, room1) == 0)
		{
			node = link_node(room, get_nb_room(lm, room));
			ft_lstadd(&((t_room *)tmp->content)->link,
			ft_lstnew(node, sizeof(t_link)));
			ft_memdel((void *)&node);
		}
		tmp = tmp->next;
	}
}

int				ft_check_link(t_lem *lm, char *room, char *room1)
{
	t_list		*tmp;
	t_list		*tmp1;

	tmp = lm->room;
	tmp1 = lm->room;
	while (tmp)
	{
		if (ft_strcmp(((t_room*)tmp->content)->name, room) == 0)
			break ;
		tmp = tmp->next;
	}
	while (tmp1)
	{
		if (ft_strcmp(((t_room*)tmp1->content)->name, room1) == 0)
			break ;
		tmp1 = tmp1->next;
	}
	if (tmp == NULL || tmp1 == NULL)
		return (-1);
	ft_create_tube(lm, room, room1);
	return (0);
}

int				ft_tube(t_lem *lm, char *str)
{
	char		**tmp;

	lm->key = true;
	if (lm->start == NULL || lm->end == NULL)
		ft_error_pars(4);
	tmp = ft_strsplit(str, '-');
	if (ft_check_link(lm, tmp[0], tmp[1]) == -1)
		ft_error_pars(5);
	del_split(tmp);
	return (0);
}
