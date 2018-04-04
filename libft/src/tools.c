/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:27:57 by kbensado          #+#    #+#             */
/*   Updated: 2017/05/25 18:30:54 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void		set_pages_size(void)
{
	size_t	max;

	max = sizeof(t_header) * 100;
	TINY_SIZE = TINY_LEN_MAX;
	SMALL_SIZE = SMALL_LEN_MAX;
}

int				get_page(size_t size)
{
	if (!TINY_SIZE || !SMALL_SIZE)
		set_pages_size();
	size += (sizeof(t_header) * 2) + 1;
	if (size <= TINY_SIZE)
		return (TINY);
	else if (size > TINY_SIZE && size <= SMALL_SIZE)
		return (SMALL);
	else
		return (LARGE);
}

t_header		**get_memory_list(int page)
{
	if (page == TINY)
		return (&g_mems_list.tiny);
	else if (page == SMALL)
		return (&g_mems_list.small);
	else
		return (&g_mems_list.large);
}

int				is_mem_between(void *ptr, void *start, void *end)
{
	if (ptr >= start && ptr <= end)
		return (1);
	else
		return (0);
}
