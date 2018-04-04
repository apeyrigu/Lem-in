/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:27:40 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:49:43 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int					ft_strisspace(char *str)
{
	size_t	i;

	i = 0;
	if (str == 0 || str[i] == 0)
		return (1);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
