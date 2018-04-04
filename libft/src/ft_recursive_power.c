/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 02:24:15 by kbensado          #+#    #+#             */
/*   Updated: 2016/02/28 06:33:23 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_rec_pow(int nb, int power)
{
	int	tmp;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power % 1 == 1)
		return (ft_rec_pow(nb, power - 1) * nb);
	else
	{
		tmp = ft_rec_pow(nb, power / 2);
		return (tmp * tmp);
	}
}

int		ft_ite_pow(int nb, int power)
{
	int i;
	int result;

	i = 1;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
