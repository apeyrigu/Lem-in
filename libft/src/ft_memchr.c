/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:02:57 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:52:58 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void						*ft_memchr(void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			*temp;

	temp = (unsigned char *)s;
	i = 0;
	if (temp == NULL || n == 0)
		return (NULL);
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
