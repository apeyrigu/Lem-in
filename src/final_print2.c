/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_print2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 02:03:14 by kbensado          #+#    #+#             */
/*   Updated: 2017/10/28 02:06:33 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

char	*get_nm_room(t_lem *s, size_t nb)
{
	t_list	*l;

	l = s->room;
	while (l)
	{
		if (((t_room *)l->content)->nb_name == nb)
			return (((t_room *)l->content)->name);
		l = l->next;
	}
	return (NULL);
}

t_final	*final_node(size_t nb, size_t room)
{
	t_final *res;

	res = ft_memalloc(sizeof(t_final));
	res->nb = nb;
	res->room = room;
	return (res);
}
