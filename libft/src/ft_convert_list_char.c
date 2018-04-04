/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_list_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 07:32:17 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/19 03:48:58 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
**	list_simp to char ** (on t_char)
*/

t_char			ft_list_to_char(t_list *list)
{
	size_t		i;
	t_char		res;

	i = D_LIST(size)(list);
	B_ZERO(res);
	if (0 == i)
		return (res);
	if (!(res.array = (char **)ft_memalloc(sizeof(char *) * i)))
	{
		WS("error malloc list_to_char");
		return (res);
	}
	res.size = i;
	i = 0;
	while (list)
	{
		res.array[i] = ft_strdup(list->content);
		i++;
		list = list->next;
	}
	return (res);
}

/*
**	reversed
**  char to list_simp key = 0 for push_back 1 for push_front
*/

t_list			*ft_char_to_list(t_char *src, ssize_t key)
{
	size_t		i;
	t_list		*res;

	res = NULL;
	i = src->size;
	if (0 == i)
		return (NULL);
	while (i < src->size)
	{
		if (0 == key)
			ADD_NODE_B(res, ft_strdup(src->array[i]),
				ft_strlen(src->array[i]));
		else
			ADD_NODE_F(res, ft_strdup(src->array[i]),
				ft_strlen(src->array[i]));
		i++;
	}
	return (res);
}
