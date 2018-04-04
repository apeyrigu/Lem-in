/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 12:53:48 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/19 04:03:51 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char			**ft_strtabnew(size_t count, ...)
{
	size_t		i;
	va_list		ap;
	char		**res;
	char		*buff;

	i = 0;
	buff = NULL;
	va_start(ap, count);
	res = ft_memalloc(sizeof(char **) * count);
	while (i < count)
	{
		buff = va_arg(ap, char *);
		res[i] = ft_strdup(buff);
		i++;
	}
	va_end(ap);
	return (res);
}

char			*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!(str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	return (str);
}
