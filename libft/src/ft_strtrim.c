/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 20:16:39 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:05:18 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	ft_start(char *s)
{
	size_t	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_end(char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	j--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (j);
}

char			*ft_strtrim(char *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tab;

	if (!s)
		return (NULL);
	k = 0;
	i = ft_start(s);
	j = ft_end(s);
	if (j - i <= 0)
		j = i - 1;
	tab = (char *)ft_memalloc(sizeof(char) * (j - i + 2));
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
