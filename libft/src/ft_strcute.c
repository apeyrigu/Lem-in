/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:51:22 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:58:51 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		ft_start(char *s, char c)
{
	int			i;

	i = 0;
	while ((s[i] == c && s[i] != '\0'))
		i++;
	return (i);
}

static int		ft_end(char *s, char c)
{
	int			j;

	j = 0;
	while (s[j] != '\0')
		j++;
	j--;
	while (s[j] == c)
		j--;
	return (j);
}

static char		*one_char(char *str)
{
	char		*tab;

	tab = ft_strnew(1);
	tab[0] = str[0];
	return (tab);
}

char			*ft_strcute(char *s, char c)
{
	int			i;
	int			j;
	int			k;
	char		*tab;

	if (!s)
		return (NULL);
	k = 0;
	i = ft_start(s, c);
	j = ft_end(s, c);
	if (j - i <= 0)
		j = i - 1;
	if (j == -1)
		return (one_char(s));
	tab = (char *)ft_memalloc(sizeof(char) * (size_t)(j - i + 2));
	if (tab == NULL)
		return (NULL);
	while (i <= j)
	{
		tab[k] = s[i];
		i++;
		k++;
	}
	tab[k] = '\0';
	return (tab);
}
