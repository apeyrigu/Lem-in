/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rebuild_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:45:21 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/28 07:45:59 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void				ft_parsset_key(t_list *lst, size_t key)
{
	while (lst)
	{
		((t_parser *)lst->content)->key = key++;
		lst = lst->next;
	}
}

/*
**	will get the data maintain inside lst and separate by q
**	n_node the number of node to rebuild/destroy
**	ltmp will store the size of the quote
*/

int					cmp_pars(size_t a, size_t b, size_t c)
{
	if (a >= b && a <= c)
		return (1);
	return (0);
}

static t_list		*ft_rebuild_on(t_list *lst, char q[1], size_t *len)
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
	while (tmp && 0 != ft_strcmp(PARSE_N(tmp), q))
	{
		ft_strcat(res, PARSE_N(tmp));
		tmp = tmp->next;
	}
	tmp = ft_strcmp(PARSE_N(lst), q) != 0 ? ft_next_quote(lst, q, true) : lst;
	tmp2 = tmp;
	tmp = tmp->next;
	while (0 != ft_strcmp(PARSE_N(tmp), q))
		ft_lstclear_n(&tmp);
	tmp2->next = tmp;
	ft_lstclear_n(&tmp2->next);
	D_PARS(morph)(&tmp2, res, QUOTE);
	*len = 0;
	return (lst);
}

ssize_t				ft_rebuild_quote(t_list *lst, char q[1])
{
	t_list			*tmp;
	size_t			ltmp;
	size_t			tok;

	ltmp = 0;
	tmp = lst;
	tok = ft_nb_quote(lst, q);
	if (1 > D_LIST(size)((t_list *)lst) || !tok)
		return (0);
	while (tok)
	{
		if (0 != ft_strcmp(PARSE_N(tmp), q))
			tmp = ft_next_quote(tmp, q, true);
		if (tmp)
			tmp = tmp->next;
		while (tmp && 0 != ft_strcmp(PARSE_N(tmp), q))
		{
			ltmp += ft_strlen(PARSE_N(tmp));
			tmp = tmp->next;
		}
		lst = ft_rebuild_on(lst, q, &ltmp);
		tmp = lst;
		tok -= 2;
	}
	return (1);
}
