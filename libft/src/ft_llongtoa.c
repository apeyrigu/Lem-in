/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llongtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 04:17:51 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/19 04:29:56 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	ft_len_num(long long n)
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

char			*ft_llongtoa(long long n)
{
	size_t		len;
	char		*result;

	len = ft_len_num(n);
	result = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (NULL == result)
		return (NULL);
	result[len] = 0;
	if ((-9223372036854775807 - 1) == n)
		return (ft_strcpy(result, "-9223372036854775808"));
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
