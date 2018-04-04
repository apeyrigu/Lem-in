/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:02:57 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:53:13 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int					ft_memcmp(void *s1, void *s2, size_t n)
{
	int				result;
	size_t			i;
	unsigned char	*data;
	unsigned char	*data2;

	i = 0;
	result = 0;
	data = (unsigned char *)s1;
	data2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (data[i] == data2[i])
			i++;
		else
			return (data[i] - data2[i]);
	}
	return (result);
}
