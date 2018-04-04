/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 17:46:59 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:57:12 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t		ft_count_substr(char *s, char c)
{
	int				i;
	size_t			nb_substr;

	nb_substr = 0;
	if (s)
	{
		i = 0;
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] && s[i] != c)
				nb_substr++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb_substr);
}

static size_t		ft_strsub_len(char *s, char c)
{
	size_t			len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static int			ft_nbwhitespaces(char *s, char c)
{
	int				skip;

	skip = 0;
	while (*s && *s == c)
	{
		skip++;
		s++;
	}
	return (skip);
}

static char			**ft_newsplit(size_t nb_substr, t_char *res)
{
	char			**newsplit;

	if (!(newsplit = (char **)ft_memalloc(sizeof(char *) *
		(size_t)(nb_substr + 1))))
	{
		res->size = 0;
		WS("error : split_char malloc failed\n");
		return (NULL);
	}
	newsplit[nb_substr] = ((void *)0);
	return (newsplit);
}

void				ft_strsplit_char(char *s, char c, t_char *split, size_t i)
{
	size_t			substr_len;
	char			*str;

	ft_bzero(split, sizeof(t_char));
	if (s)
	{
		str = s;
		split->size = ft_count_substr(s, c);
		if (!(split->array = ft_newsplit(split->size, split)))
			return ;
		while (i < split->size)
		{
			str += ft_nbwhitespaces(str, c);
			substr_len = ft_strsub_len(str, c);
			if (!(split->array[i] = ft_strsub(str, 0, substr_len)))
			{
				split->size = 0;
				WS("error : split_char malloc failed\n");
				return ;
			}
			i++;
			str += substr_len;
		}
	}
}
