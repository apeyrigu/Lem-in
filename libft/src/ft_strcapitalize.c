/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 13:36:14 by kbensado          #+#    #+#             */
/*   Updated: 2015/12/28 12:21:24 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i++])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	i = 1;
	if (str[0] >= 'a' && str[i] <= 'z')
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if ((str[i - 1] <= 96 && str[i - 1] >= 91) ||
				(str[i - 1] <= 64 && str[i - 1] >= 58) ||
				str[i - 1] >= 123 || str[i - 1] <= 47)
				str[i] -= 32;
			i++;
		}
		else
			i++;
	}
	return (str);
}
