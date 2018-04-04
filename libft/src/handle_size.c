/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:40:38 by kbensado          #+#    #+#             */
/*   Updated: 2017/05/25 18:24:58 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static t_header		*handle_large(size_t size)
{
	t_header		**list;
	t_header		*block;

	list = get_memory_list(LARGE);
	block = find_free_mem(list, size, LARGE);
	if (block)
		block->is_free = 0;
	else
	{
		block = create_block(size + sizeof(t_header));
		insert_header(list, block);
	}
	return (block);
}

static t_header		*handle_tiny_small(int page, size_t size, int page_size)
{
	t_header		**list;
	t_header		*block;
	t_header		*new;

	list = get_memory_list(page);
	block = find_free_mem(list, size, page);
	if (block)
		block->is_free = 0;
	else
	{
		block = create_block(page_size);
		if (block == MAP_FAILED)
			return (NULL);
		insert_header(list, block);
		new = set_header(block->mem + size,
			page_size - (sizeof(t_header) * 2) - size);
		block->size = size;
		insert_header(list, new);
	}
	return (block);
}

t_header			*handle_sizes(size_t size)
{
	int				page;
	t_header		*block;

	page = get_page(size);
	if (page == TINY)
		block = handle_tiny_small(page, size, TINY_SIZE);
	else if (page == SMALL)
		block = handle_tiny_small(page, size, SMALL_SIZE);
	else
		block = handle_large(size);
	return (block);
}
