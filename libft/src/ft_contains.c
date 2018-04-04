/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 22:21:14 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/19 03:56:49 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

bool			ft_contains_int(int *src, int target, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (src[i] == target)
			return (true);
		i++;
	}
	return (false);
}

bool			ft_contains_str(char **src, char *target)
{
	size_t		i;

	i = 0;
	while (src[i])
	{
		if (ft_strcmp(src[i], target) == 0)
			return (true);
		i++;
	}
	return (false);
}

bool			ft_contains_char(char *src, char target)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		if (src[i] == target)
			return (true);
		i++;
	}
	return (false);
}

int				ft_contains_int_at(int *src, int target, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (src[i] == target)
			return ((int)i);
		i++;
	}
	return (-1);
}

int				ft_contains_str_at(char **src, char *target, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(src[i], target) == 0)
			return ((int)i);
		i++;
	}
	return (-1);
}
