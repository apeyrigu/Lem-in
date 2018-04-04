/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 23:09:45 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/28 23:40:33 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		ft_pars_lm(t_lem *lm, char *test)
{
	while (get_next_line(0, &test) != 0)
	{
		if (lm->fourmi == 0)
			ft_fourmi(lm, test);
		else if (test[0] == '#' || test[0] == 'L')
		{
			if (ft_comment(lm, test) == 0)
				continue ;
		}
		else if (ft_strchr(test, '-') && ft_strchr(test, ' ') == NULL)
		{
			if (ft_tube(lm, test) == -1)
				return (0);
		}
		else
		{
			if (ft_room(lm, test, 0) == -1)
				return (-1);
		}
		ft_lstadd_back(&lm->view, ft_lstnew((void *)test,
			sizeof(char) * ft_strlen(test) + 1));
		ft_memdel((void*)&test);
	}
	ft_memdel((void*)&test);
	return (0);
}

void	print_link(t_lem *s)
{
	t_list	*t;
	t_list	*p;

	t = s->room;
	while (t)
	{
		p = ((t_room *)t->content)->link;
		while (p)
			p = p->next;
		t = t->next;
	}
}

void	nb_link(t_lem *lm)
{
	t_list	*tmp;

	tmp = lm->room;
	while (tmp)
	{
		((t_room *)tmp->content)->nb_link = ft_lstsize(
		((t_room *)tmp->content)->link);
		tmp = tmp->next;
	}
}

int		main(void)
{
	t_lem	lm;

	ft_bzero(&lm, sizeof(t_lem));
	ft_pars_lm(&lm, NULL);
	if (lm.command == true)
		ft_error_pars(0);
	nb_link(&lm);
	if (lm.view == NULL || lm.room == NULL)
		return (0);
	ft_table_create(&lm, NULL, NULL);
	if (lm.tab == NULL)
		return (0);
	ft_found_way(&lm, lm.tab);
	final_print(&lm);
	free_all(&lm);
	return (0);
}
