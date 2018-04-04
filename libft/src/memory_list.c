/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:43:04 by kbensado          #+#    #+#             */
/*   Updated: 2017/05/25 18:52:52 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static t_header		*is_available_memory(t_header **list, size_t size)
{
	t_header		*tmp;
	t_header		*new;

	tmp = *list;
	new = NULL;
	while (tmp)
	{
		if (tmp->is_free < 0 && tmp->is_free > 1)
			return (NULL);
		if (tmp->is_free == 1 && tmp->size >= size)
			if (!new || (new && new->size > tmp->size))
				new = tmp;
		tmp = tmp->next;
	}
	return (new);
}

t_header			*find_free_mem(t_header **list, size_t size, int page)
{
	t_header		*tmp;
	t_header		*new;

	new = is_available_memory(list, size);
	if (new)
	{
		if (SIZE_LEFT > 0 && (page == TINY || page == SMALL))
		{
			tmp = new;
			new = set_header(new->mem + size, SIZE_LEFT);
			new->next = tmp;
			tmp->size = size;
			if (*list == tmp)
				*list = new;
			return (tmp);
		}
		return (new);
	}
	return (NULL);
}

void				insert_header(t_header **list, t_header *block)
{
	block->next = *list;
	*list = block;
}

t_header			*set_header(t_header *block, size_t size)
{
	t_header		*new;

	new = block;
	new->mem = (void *)new + sizeof(t_header);
	new->size = size;
	new->is_free = 1;
	new->next = NULL;
	return (new);
}

t_header			*create_block(size_t size)
{
	t_header		*block;

	if ((block = MAP(size)) == MAP_FAILED)
		return (NULL);
	block->mem = block + 1;
	block->size = size - sizeof(t_header);
	block->is_free = 0;
	block->next = NULL;
	return (block);
}
