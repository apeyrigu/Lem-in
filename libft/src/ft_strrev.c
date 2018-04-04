/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:07:38 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:03:21 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char			*ft_strrev(char *str)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		temp;

	if (str)
	{
		i = 0;
		size = ft_strlen(str);
		j = size / 2;
		while (i < j)
		{
			temp = str[i];
			str[i] = str[size - i - 1];
			str[size - i - 1] = temp;
			i++;
		}
	}
	return (str);
}
