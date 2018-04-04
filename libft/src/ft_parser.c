/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:38:14 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/28 07:47:57 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_parsmorph(t_list **lst, char *new, enum e_type type)
{
	t_list	*tmp;

	tmp = *lst;
	ft_free(PARSE_N(tmp));
	PARSE_N(tmp) = NULL;
	PARSE_N(tmp) = ft_strdup(new);
	tmp->content_size = ft_strlen(new);
	PARSE_SIZE(tmp) = ft_strlen(new);
	PARSE_TYPE(tmp) = type;
}

t_parser	*ft_parsnode(void *content, size_t content_size,
			enum e_type type)
{
	t_parser	*list;

	list = (t_parser *)ft_memalloc(sizeof(t_parser));
	if (!list)
		return (NULL);
	if (content == NULL)
	{
		list->content_size = 0;
		list->content = NULL;
		list->type = 0;
	}
	else
	{
		list->content = ft_strnew(content_size);
		list->type = type;
		list->content_size = content_size;
		if (!list->content)
			return (NULL);
		ft_memcpy(list->content, content, content_size);
	}
	return (list);
}

t_list		*ft_parsnew(void *content, size_t content_size,
			enum e_type type)
{
	t_list	*list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (content == NULL)
	{
		list->content_size = 0;
		list->content = NULL;
	}
	else
	{
		list->content_size = content_size;
		list->content = D_PARS(node)(content, content_size, type);
		if (!list->content)
			return (NULL);
	}
	list->next = NULL;
	return (list);
}

static void	ft_parsprint2(t_list *p, bool key)
{
	while (p && key == true)
	{
		ft_printf("%s", PARSE_N(p));
		p = p->next;
		if (!p)
			WS("");
	}
}

void		ft_parsprint(t_list *p, bool key)
{
	t_list	*tmp;

	tmp = p;
	while (p && key == false)
	{
		WS("--------------------------");
		ft_printf("%s\nKey = %zu\nSize = %zu\n", PARSE_N(p),
			PARSE_KEY(p), PARSE_SIZE(p));
		if (PARSE_TYPE(p) == CHAR)
			WS("CHAR");
		if (PARSE_TYPE(p) == STRING)
			WS("STRING");
		if (PARSE_TYPE(p) == TOKEN)
			WS("TOKEN");
		if (PARSE_TYPE(p) == QUOTE)
			WS("QUOTE");
		if (PARSE_TYPE(p) == LIST)
			WS("LIST");
		if (PARSE_TYPE(p) == INT)
			WS("INT");
		if (PARSE_TYPE(p) == CONDITION)
			WS("CONDITION");
		p = p->next;
	}
	ft_parsprint2(tmp, key);
}
