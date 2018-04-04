/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:36:48 by kbensado          #+#    #+#             */
/*   Updated: 2017/01/08 19:52:38 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_print_tabi(int **tab, size_t w, size_t l)
{
	size_t	i;
	size_t	f;

	i = 0;
	f = 0;
	while (i < w)
	{
		while (f < l)
		{
			ft_putnbr(tab[i][f]);
			write(1, " ", 1);
			f++;
		}
		write(1, "\n", 1);
		f = 0;
		i++;
	}
}
