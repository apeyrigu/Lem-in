/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 16:29:59 by kbensado          #+#    #+#             */
/*   Updated: 2017/07/29 18:02:34 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t		is_optionc(char *src, t_char range, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		res;

	i = 1;
	j = 0;
	res = 0;
	while (i < len + 1)
	{
		while (j < range.size)
		{
			if (src[i] == range.array[j][0] && ft_strlen(range.array[j]) == 1)
			{
				res++;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

bool		is_optionw(char *src, t_char range)
{
	size_t		i;

	i = 0;
	while (i < range.size)
	{
		if (ft_strncmp(src + 1, range.array[i], ft_strlen(src) - 1) == 0)
			return (true);
		i++;
	}
	return (false);
}

size_t		get_nb_arg(int ac, char **av, t_char range, int i)
{
	size_t		res;
	size_t		tmp;

	tmp = 0;
	res = 0;
	while (++i < ac && av[i][0] == '-' && ft_strlen(av[i]) > 1)
	{
		if (is_optionw(av[i], range))
			res++;
		else
		{
			tmp = is_optionc(av[i], range, ft_strlen(av[i] + 1));
			if (tmp > 0)
				res += tmp;
			else
				return (0);
		}
	}
	return (res);
}
