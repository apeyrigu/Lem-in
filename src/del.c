/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:29:02 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/28 01:57:24 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	del_res(t_res **s)
{
	t_res	*tmp;
	t_res	*tmp2;

	tmp = *s;
	tmp2 = *s;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp2->next;
		ft_memdel((void *)&tmp2->content);
		ft_memdel((void *)&tmp2);
	}
	*s = tmp;
}

void	del_link(t_list **s)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_link	*tmp3;

	tmp = *s;
	tmp2 = *s;
	tmp3 = NULL;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp2->next;
		tmp3 = ((t_link *)tmp2->content);
		ft_memdel((void *)&tmp3->name);
		ft_memdel((void *)&tmp3);
		ft_memdel((void *)&tmp2);
	}
	*s = tmp;
}

void	del_view(t_list **s)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *s;
	tmp2 = *s;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp2->next;
		ft_memdel((void *)&tmp2->content);
		ft_memdel((void *)&tmp2);
	}
	*s = tmp;
}

void	del_room(t_list **s)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_room	*tmp3;

	tmp = *s;
	tmp2 = *s;
	tmp3 = NULL;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp2->next;
		tmp3 = ((t_room *)tmp2->content);
		del_link(&tmp3->link);
		ft_memdel((void *)&tmp3->name);
		ft_memdel((void *)&tmp3);
		ft_memdel((void *)&tmp2);
	}
	*s = tmp;
}

void	free_all(t_lem *s)
{
	del_room(&s->room);
	del_view(&s->view);
	del_res(&s->tab);
	ft_memdel((void *)&s->final);
	ft_memdel((void *)&s->start);
	ft_memdel((void *)&s->end);
}
