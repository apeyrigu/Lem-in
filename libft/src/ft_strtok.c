/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 06:08:48 by kbensado          #+#    #+#             */
/*   Updated: 2017/07/22 17:19:39 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
**	ft_strtok parse line and create a list of token
**	char *s = string to parse, char *del = delimiter
**	bool add on ft_is_present if u want to keep the token in the list or not
*/

static ssize_t	ft_is_present(char c, char *del)
{
	size_t	i;

	i = 0;
	while (del[i])
	{
		if (c == del[i])
			return (1);
		else
			i++;
	}
	return (0);
}

size_t			ft_nb_quote(t_list *lst, char q[1])
{
	size_t		i;

	i = 0;
	while (lst)
	{
		if (0 == ft_strcmp(PARSE_N(lst), q))
			i++;
		lst = lst->next;
	}
	if (0 < i && 0 == i % 2)
		return (i);
	return (0);
}

/*
**	will get the next node with the char 'q' as delimiter
**	if key == 0 will search the next quote and give the next node
**	else the actual node with dat quote.
*/

t_list			*ft_next_quote(t_list *lst, char q[1], bool key)
{
	size_t		i;

	i = 0;
	if (key)
	{
		while (lst && 0 != ft_strcmp(PARSE_N(lst), q))
		{
			i++;
			lst = lst->next;
		}
		if (0 == i)
			return (lst->next);
		return (lst);
	}
	while (lst && 0 != ft_strcmp(PARSE_N(lst), q))
		lst = lst->next;
	return (lst);
}

t_list			*ft_strtok_list(char *s, char *del, bool add)
{
	size_t	i;
	size_t	j;
	t_list	*lst;

	i = 0;
	j = 0;
	lst = NULL;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (1 == ft_is_present(s[i], del))
		{
			if (i - j > 0)
				ADD_NODE_PB(lst, ft_strsub(s, j, i - j), i - j, STRING);
			add ? ADD_NODE_PB(lst, &s[i], 1, CHAR) : (void)s;
			j = i + 1;
		}
		i++;
	}
	if (i > 0 && 1 == ft_is_present(s[i - 1], del))
		return (lst);
	ADD_NODE_PB(lst, ft_strsub(s, j, i - j), i - j, STRING);
	return (lst);
}
