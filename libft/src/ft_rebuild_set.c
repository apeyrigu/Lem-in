/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rebuild_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 07:10:14 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/28 07:46:28 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t		ft_nb_set(t_list *lst, char q[1])
{
	size_t			i;

	i = 0;
	while (lst)
	{
		if (0 == ft_strcmp(PARSE_N(lst), q))
			i++;
		lst = lst->next;
	}
	return (i);
}

static t_list		*ft_rebuild_on(t_list *lst, char q[1], char w[1],
					size_t *len)
{
	char			*res;
	t_list			*tmp;
	size_t			key;
	t_list			*tmp2;

	res = ft_strnew(*len);
	tmp = lst;
	tmp = ft_strcmp(PARSE_N(lst), q) != 0 ? ft_next_quote(lst, q, true) : lst;
	tmp = tmp->next;
	key = ((t_parser *)tmp->content)->key;
	while (tmp && 0 != ft_strcmp(PARSE_N(tmp), w))
	{
		ft_strcat(res, PARSE_N(tmp));
		tmp = tmp->next;
	}
	tmp = ft_strcmp(PARSE_N(lst), q) != 0 ? ft_next_quote(lst, q, true) : lst;
	tmp2 = tmp;
	tmp = tmp->next;
	while (0 != ft_strcmp(PARSE_N(tmp), w))
		ft_lstclear_n(&tmp);
	tmp2->next = tmp;
	ft_lstclear_n(&tmp2->next);
	D_PARS(morph)(&tmp2, res, CONDITION);
	*len = 0;
	return (lst);
}

ssize_t				ft_rebuild_set(t_list *lst, char q[1], char w[1],
					size_t tok)
{
	t_list			*tmp;
	size_t			ltmp;

	ltmp = 0;
	tmp = lst;
	tok = ft_nb_set(lst, q);
	tok = tok + ft_nb_set(lst, w);
	if (1 > D_LIST(size)((t_list *)lst) || !tok)
		return (0);
	while (tok)
	{
		if (0 != ft_strcmp(PARSE_N(tmp), q))
			tmp = ft_next_quote(tmp, q, true);
		if (tmp)
			tmp = tmp->next;
		while (tmp && 0 != ft_strcmp(PARSE_N(tmp), w))
		{
			ltmp += ft_strlen(PARSE_N(tmp));
			tmp = tmp->next;
		}
		lst = ft_rebuild_on(lst, q, w, &ltmp);
		tmp = lst;
		tok -= 2;
	}
	return (1);
}
