/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:40:38 by kbensado          #+#    #+#             */
/*   Updated: 2017/05/25 18:19:54 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = f_malloc(size);
	if (!ret)
	{
		WS("MALLOC ERROR RETURN NULL");
		return (NULL);
	}
	ft_bzero(ret, size);
	return (ret);
}

void	*f_malloc(size_t size)
{
	t_header	*block;

	if (size <= 0)
		return (NULL);
	if (pthread_mutex_lock(&g_malloc_lock[0]) == EINVAL)
	{
		pthread_mutex_init(&g_malloc_lock[0], NULL);
		pthread_mutex_lock(&g_malloc_lock[0]);
	}
	block = handle_sizes(size);
	pthread_mutex_unlock(&g_malloc_lock[0]);
	pthread_mutex_destroy(&g_malloc_lock[0]);
	return (block->mem);
}
