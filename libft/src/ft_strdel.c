/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 12:53:57 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/25 19:54:43 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
**	enleve less dans src, free src si del == true
*/

char			*ft_strless(char *less, char *src, bool del)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*res;

	i = 0;
	len = ft_strlen(src);
	j = ft_strlen(less);
	res = ft_strnew(len - j);
	while (j < len)
	{
		res[i] = src[j];
		j++;
		i++;
	}
	if (del == true)
		ft_memdel((void *)&src);
	if (ft_strcmp("", res) == 0)
	{
		ft_memdel((void *)&res);
		return (NULL);
	}
	return (res);
}

void			ft_strdel(char **as)
{
	if (as != NULL)
	{
		ft_free(*as);
		*as = NULL;
	}
}
