/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:53:38 by kbensado          #+#    #+#             */
/*   Updated: 2017/07/22 17:18:21 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static t_header		*get_ptr(void *ptr, t_header *end, t_header *start)
{
	t_header		*tmp;

	tmp = end;
	while (tmp && tmp != start)
	{
		if (is_mem_between(ptr, (void *)tmp, tmp->mem + tmp->size))
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp && is_mem_between(ptr, (void *)tmp, tmp->mem + tmp->size))
		return (tmp);
	return (NULL);
}

static t_header		*get_start_page(t_header *start)
{
	t_header		*tmp;

	tmp = start;
	while (tmp->next)
	{
		if (tmp->next && ((void *)tmp -
					((tmp->next)->mem + (tmp->next)->size)) != 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

static t_block		*get_memory_page(void *p, t_header **page, t_block *block)
{
	block->start = NULL;
	block->end = *page;
	block->prev = *page;
	while (block->end)
	{
		block->start = get_start_page(block->end);
		if (is_mem_between(p, ((void *)block->start),
					(block->end)->mem + (block->end)->size))
		{
			return (block);
		}
		block->prev = block->start;
		block->end = (!block->start) ? NULL : (block->start)->next;
	}
	block->start = NULL;
	block->end = NULL;
	block->prev = NULL;
	return (NULL);
}

t_block				*find_ptr_in_page(void *ptr, t_block *block)
{
	t_header		**header[4];
	int				i;

	i = 0;
	header[0] = &(g_mems_list.tiny);
	header[1] = &(g_mems_list.small);
	header[2] = &(g_mems_list.large);
	header[3] = NULL;
	while (header[i])
	{
		if (get_memory_page(ptr, header[i], block) != NULL)
		{
			block->selected = get_ptr(ptr, block->end, block->start);
			block->page = header[i];
			return (block);
		}
		i++;
	}
	return (NULL);
}
