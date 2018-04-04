/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:44:28 by kbensado          #+#    #+#             */
/*   Updated: 2017/05/25 18:28:29 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void		*get_memory(void *mem, size_t size)
{
	t_block		block;
	void		*ret;

	ret = NULL;
	if (find_ptr_in_page(mem, &block))
	{
		if ((block.selected)->is_free == 1)
			return (NULL);
		if ((block.selected)->size > size)
			return ((block.selected)->mem);
		ret = ft_malloc(size);
		if (ret)
		{
			ft_memcpy(ret, mem, size);
			ft_free(mem);
			mem = NULL;
		}
	}
	return (ret);
}

void			*realloc(void *mem, size_t size)
{
	void	*ret;

	ret = NULL;
	if (pthread_mutex_lock(&g_malloc_lock[3]) == EINVAL)
	{
		pthread_mutex_init(&g_malloc_lock[3], NULL);
		pthread_mutex_lock(&g_malloc_lock[3]);
	}
	if (!mem || !size)
	{
		WS("1");
		ret = ft_malloc(size);
	}
	else
	{
		WS("2");
		ret = get_memory(mem, size);
	}
	pthread_mutex_unlock(&g_malloc_lock[3]);
	return (ret);
}
