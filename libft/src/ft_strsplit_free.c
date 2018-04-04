/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 02:25:13 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/20 07:54:53 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void			ft_strsplit_free(t_char *p)
{
	size_t		i;

	i = 0;
	if (0 == p->size)
	{
		WS("error : strsplit_free abord 0 size detected");
		return ;
	}
	if (0 == p->array)
	{
		WS("error : strsplit_free abord NULL array detected");
		return ;
	}
	else
	{
		while (i < p->size)
		{
			ft_memdel((void *)&p->array[i]);
			i++;
		}
		ft_memdel((void *)&p->array);
	}
	p->size = 0;
}
