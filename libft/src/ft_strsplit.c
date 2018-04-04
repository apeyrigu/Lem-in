/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 17:46:59 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:04:22 by kbensado         ###   ########.fr       */
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

static size_t		ft_nbwhitespaces(char *s, char c)
{
	size_t			skip;

	skip = 0;
	while (*s && *s == c)
	{
		skip++;
		s++;
	}
	return (skip);
}

static char			**ft_newsplit(size_t nb_substr)
{
	char			**newsplit;

	if (!(newsplit = (char **)ft_memalloc(sizeof(char *) * (nb_substr + 1))))
		return (NULL);
	newsplit[nb_substr] = ((void *)0);
	return (newsplit);
}

char				**ft_strsplit(char *s, char c)
{
	size_t			substr_len;
	size_t			split_i;
	char			**split;
	size_t			nb_substr;
	char			*str;

	split = NULL;
	if (s)
	{
		split_i = 0;
		str = (char*)s;
		nb_substr = ft_count_substr(s, c);
		if (!(split = ft_newsplit(nb_substr)))
			return (NULL);
		while (split_i < nb_substr)
		{
			str += ft_nbwhitespaces(str, c);
			substr_len = ft_strsub_len(str, c);
			if (!(split[split_i] = ft_strsub(str, 0, substr_len)))
				return (NULL);
			split_i++;
			str += substr_len;
		}
	}
	return (split);
}
