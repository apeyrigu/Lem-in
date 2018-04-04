/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:27:50 by kbensado          #+#    #+#             */
/*   Updated: 2017/05/25 18:22:49 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void		*handle_case(size_t num, size_t nsize)
{
	size_t		size;
	void		*ptr;

	if (!num || !nsize)
		return (NULL);
	size = num * nsize;
	if (nsize != size / num)
		return (NULL);
	ptr = ft_malloc(size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void			*calloc(size_t num, size_t nsize)
{
	void		*ptr;

	if (pthread_mutex_lock(&g_malloc_lock[1]) == EINVAL)
	{
		pthread_mutex_init(&g_malloc_lock[1], NULL);
		pthread_mutex_lock(&g_malloc_lock[1]);
	}
	ptr = handle_case(num, nsize);
	pthread_mutex_unlock(&g_malloc_lock[1]);
	pthread_mutex_destroy(&g_malloc_lock[1]);
	return (ptr);
}
