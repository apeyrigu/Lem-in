/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:30:06 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:03:01 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t			ft_strlcpy(char *dst, char *src, size_t n)
{
	size_t		i;
	char		*s1;
	char		*s2;

	s1 = dst;
	s2 = src;
	i = n;
	if (i != 0)
	{
		while (--i != 0)
		{
			if ((*s1++ = *s2++) == '\0')
				break ;
		}
	}
	if (i == 0)
	{
		if (n != 0)
			*s1 = '\0';
		while (*s2++)
			;
	}
	return ((size_t)(s2 - src - 1));
}
