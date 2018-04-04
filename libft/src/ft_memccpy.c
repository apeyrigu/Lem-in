/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:04:11 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:58:52 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void						*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char			*temp;
	unsigned const char		*temp2;
	size_t					i;

	i = 0;
	temp = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	while (n--)
	{
		temp[i] = temp2[i];
		if ((unsigned char)c == temp2[i])
			return (temp + i + 1);
		i++;
	}
	return (NULL);
}
