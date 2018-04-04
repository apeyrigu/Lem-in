/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 00:46:55 by kbensado          #+#    #+#             */
/*   Updated: 2017/07/29 18:01:58 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
** range has to be ended by NULL
*/

void				del_t_char(t_char *ptr)
{
	size_t			i;

	i = 0;
	while (i < ptr->size)
	{
		ft_free(ptr->array[i]);
		i++;
	}
	ft_free(ptr->array);
}

t_char				ft_set_arg(size_t len, ...)
{
	va_list			ap;
	size_t			i;
	t_char			res;
	char			*buff;

	i = 0;
	res.array = (char **)ft_memalloc(sizeof(char *) * len);
	res.size = len;
	va_start(ap, len);
	while (i < len)
	{
		buff = va_arg(ap, char *);
		res.array[i] = ft_strdup(buff);
		i++;
	}
	va_end(ap);
	return (res);
}

static void			is_optioncw(char *src, t_char range, size_t len, t_arg *res)
{
	size_t			i;
	size_t			j;

	i = 1;
	j = 0;
	while (i < len + 1)
	{
		while (j < range.size)
		{
			if (src[i] == range.array[j][0] && ft_strlen(range.array[j]) == 1)
			{
				res->opt.array[res->i++] = ft_strdup(range.array[j]);
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void			fill_opt(int ac, char **av, t_char range, t_arg *res)
{
	int				i;
	size_t			tmp;

	tmp = 0;
	i = 0;
	while (++i < ac && av[i][0] == '-' && ft_strlen(av[i]) > 1)
	{
		if (is_optionw(av[i], range))
			res->opt.array[res->i++] = ft_strdup(av[i] + 1);
		else
			is_optioncw(av[i], range, ft_strlen(av[i] + 1), res);
	}
}

t_arg				ft_get_arg(char **av, int ac, t_char range, int i)
{
	int				j;
	t_arg			res;

	j = -1;
	ft_bzero(&res, sizeof(t_arg));
	res.nb_opt = get_nb_arg(ac, av, range, 0);
	while (++i < ac && av[i][0] == '-')
	{
		res.inc++;
	}
	if (res.nb_opt > 0)
	{
		res.opt.array = ft_memalloc(sizeof(char *) * res.nb_opt);
		fill_opt(ac, av, range, &res);
	}
	res.i = 0;
	del_t_char(&range);
	return (res);
}
