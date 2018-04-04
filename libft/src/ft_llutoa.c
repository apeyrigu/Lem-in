/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 20:43:03 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/26 20:43:05 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	ft_len_num(long long unsigned n)
{
	size_t		len;

	if (0 == n)
		return (1);
	len = 0;
	while (0 != n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_llutoa(long long unsigned n)
{
	size_t		len;
	char		*result;

	len = ft_len_num(n);
	result = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (NULL == result)
		return (NULL);
	result[len] = 0;
	if (0 == n)
		result[0] = '0';
	while (0 != n)
	{
		len--;
		result[len] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
