/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloctab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:29:30 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/10 21:50:21 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int			**ft_memalloctab(size_t w, size_t l)
{
	int		**tab;
	size_t	i;

	i = 0;
	tab = (int **)ft_memalloc(sizeof(int *) * w);
	if (tab == NULL)
		return (NULL);
	while (i < w)
	{
		tab[i] = ft_memalloc(sizeof(int) * l);
		i++;
	}
	return (tab);
}
