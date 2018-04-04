/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 20:18:16 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/20 00:47:57 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char			*ft_strmap(char *s, char (*f)(char))
{
	char		*str;
	size_t		i;

	i = 0;
	if (s && f)
	{
		str = (char *)ft_memalloc(sizeof(char) * ft_strlen(s) + 1);
		if (str == NULL)
			return (NULL);
		while (i < ft_strlen(s))
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
