/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:27:51 by kbensado          #+#    #+#             */
/*   Updated: 2017/05/25 18:31:56 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t		free_for_all(t_header *start, t_header *end)
{
	t_header		*tmp;
	size_t			len;
	t_header		*to_end;

	tmp = start;
	len = 1;
	to_end = (!end) ? end : end->next;
	while (tmp && tmp != to_end)
	{
		if (tmp->is_free == 0)
			return (0);
		len += tmp->size + sizeof(t_header);
		tmp = tmp->next;
	}
	return (len - 1);
}

static void			free_memory(t_header **page, t_block *block)
{
	size_t			size;
	int				ret;

	(block->selected)->is_free = 1;
	size = free_for_all(block->end, block->start);
	if (size > 0 && ((block->start)->next != NULL || size > SMALL_SIZE))
	{
		(block->prev)->next = (block->start)->next;
		if (*page == block->end)
		{
			*page = (block->start)->next;
		}
		ret = munmap(block->start, size);
	}
}

void				ft_free(void *ptr)
{
	t_block			block;

	if (pthread_mutex_lock(&g_malloc_lock[2]) == EINVAL)
	{
		pthread_mutex_init(&g_malloc_lock[2], NULL);
		pthread_mutex_lock(&g_malloc_lock[2]);
	}
	if (find_ptr_in_page(ptr, &block))
	{
		free_memory(block.page, &block);
	}
	pthread_mutex_unlock(&g_malloc_lock[2]);
	pthread_mutex_unlock(&g_malloc_lock[2]);
}
