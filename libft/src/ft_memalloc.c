/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 12:50:27 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 13:52:28 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;
	char	*t;

	i = 0;
	mem = (void *)malloc(size);
	if (mem == NULL)
	{
		WS("Malloc error");
		exit(42);
		return (NULL);
	}
	t = (char *)mem;
	ft_bzero(mem, size);
	return (mem);
}
