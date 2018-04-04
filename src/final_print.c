/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:23:51 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/28 02:08:33 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		move(t_list *final, t_lem *lm)
{
	static size_t	i = 0;
	t_list			*tmp;
	size_t			len;
	size_t			j;

	len = 0;
	j = 0;
	tmp = final;
	if (i < lm->size)
		i++;
	while (tmp && len < i)
	{
		if (j == lm->fourmi)
			return ;
		j++;
		((t_final *)tmp->content)->nb++;
		tmp = tmp->next;
		len++;
	}
}

void		del_full(t_list **final, size_t target)
{
	t_list	*tmp;
	t_final	*tmp2;

	tmp = *final;
	tmp2 = ((t_final *)tmp->content);
	if (((t_final *)tmp->content)->nb == target)
	{
		*final = tmp->next;
		ft_memdel((void *)&tmp2);
		ft_memdel((void *)&tmp);
	}
}

void		print_final(t_list *final, t_lem *s, size_t i)
{
	size_t	len;
	t_list	*tmp;

	tmp = final;
	len = s->fourmi;
	if (i >= len)
		return ;
	if (tmp == NULL)
		return ;
	if (((t_final *)tmp->content)->nb == 0)
		return ;
	print_final(tmp->next, s, ++i);
	ft_printf("L%s-%zu ", get_nm_room(s, ((t_final *)tmp->content)->room),
	((t_final *)tmp->content)->nb);
}

void		print_std(t_list *s)
{
	t_list	*t;

	t = s;
	while (t)
	{
		WS((char *)t->content);
		t = t->next;
	}
	WS("");
}

void		final_print(t_lem *lm)
{
	t_list	*final;
	t_final	*tmp;
	size_t	len;
	size_t	i;

	len = lm->size - 1;
	i = 1;
	final = NULL;
	tmp = NULL;
	print_std(lm->view);
	while (len--)
	{
		tmp = final_node(0, lm->final[i - 1]);
		ft_lstadd(&final, ft_lstnew((void *)tmp, sizeof(t_final)));
		i++;
		ft_memdel((void *)&tmp);
	}
	while (final)
	{
		move(final, lm);
		print_final(final, lm, 0);
		WS("");
		del_full(&final, lm->fourmi);
	}
}
