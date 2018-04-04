/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 22:01:53 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:49:40 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t			*len_fill2(char *str, char sep[3], size_t *tab)
{
	size_t				index;
	size_t				i;

	index = 0;
	i = 0;
	while (STRING_TEST)
		i++;
	while (str[i])
	{
		if (STRING_TEST)
		{
			tab[index] = i;
			index++;
			while (STRING_TEST)
				i++;
		}
		else
			i++;
	}
	ft_isspace(str[i - 1]) ? (size_t)i : (tab[index] = i);
	tab[index] = i;
	return (tab);
}

static size_t			*len_fill(char *str, char sep[3],
							size_t *tab, size_t l)
{
	size_t				index;
	size_t				i;

	index = 0;
	i = 0;
	while (STRING_TEST)
		i++;
	while (str[i])
	{
		if (STRING_TEST)
		{
			tab[index] = l;
			l = 0;
			while (STRING_TEST)
				i++;
			str[i] != 0 ? index++ : (size_t)index;
		}
		else
		{
			i++;
			l++;
		}
	}
	ft_isspace(str[i - 1]) == 1 ? (size_t)i : (tab[index] = l);
	return (tab);
}

static int				ft_nb_word(char *str, size_t i,
							char sep[3], size_t j)
{
	size_t				l;

	l = 0;
	while (STRING_TEST)
		i++;
	while (str[i])
	{
		if (STRING_TEST)
		{
			l = 0;
			while (STRING_TEST)
				i++;
			if (str[i] != 0)
				j++;
		}
		else
		{
			i++;
			l++;
		}
	}
	return ((int)j);
}

static void				free_garbage(size_t *tab, size_t *tab2)
{
	ft_free(tab);
	ft_free(tab2);
}

char					**ft_strsplit2(char *str, char c, char b, char **tab)
{
	size_t				nb_word;
	size_t				*len_word;
	size_t				*len_word2;
	char				sep[3];
	int					i;

	i = -1;
	sep[0] = c;
	sep[1] = b;
	sep[2] = '\t';
	if (ft_strisspace(str) || str[0] == '\0')
		return (NULL);
	nb_word = (size_t)ft_nb_word(str, 0, sep, 1);
	if (!(len_word = ft_memalloc(sizeof(int) * nb_word + 1)))
		return (NULL);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * nb_word + 1)))
		return (NULL);
	len_word2 = ft_memalloc(sizeof(int) * nb_word + 1);
	len_word = len_fill(str, sep, len_word, 0);
	len_word2 = len_fill2(str, sep, len_word2);
	while (++i < (int)nb_word)
		tab[i] = ft_strsub(str, len_word2[i] - len_word[i], len_word[i]);
	free_garbage(len_word2, len_word);
	tab[i] = NULL;
	return (tab);
}
