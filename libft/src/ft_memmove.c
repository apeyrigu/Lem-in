/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:02:57 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:53:49 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memmove(void *dst, void *src, size_t len)
{
	char	c;

	if (len)
	{
		c = *(char *)src;
		ft_memmove((char *)dst + 1, (char *)src + 1, len - 1);
		*(char *)dst = c;
	}
	return (dst);
}
