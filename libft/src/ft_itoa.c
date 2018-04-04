/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 20:29:23 by kbensado          #+#    #+#             */
/*   Updated: 2015/12/28 12:18:14 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	ft_len_num(int n)
{
	size_t		len;

	if (0 == n)
		return (1);
	len = 0;
	if (0 > n)
		len = 1;
	while (0 != n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*result;

	len = ft_len_num(n);
	result = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (NULL == result)
		return (NULL);
	result[len] = 0;
	if ((-2147483647 - 1) == n)
		return (ft_strcpy(result, "-2147483648"));
	if (0 > n)
	{
		result[0] = '-';
		n = -n;
	}
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
