/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:00:29 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/13 16:51:08 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memdup(void *src, size_t n)
{
	size_t	i;
	void	*res;

	i = 0;
	res = ft_memalloc(n);
	while (i < n)
	{
		((char *)res)[i] = ((char *)src)[i];
		i++;
	}
	return (res);
}

void		*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
