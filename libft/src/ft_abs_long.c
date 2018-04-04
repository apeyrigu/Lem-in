/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:23:00 by kbensado          #+#    #+#             */
/*   Updated: 2017/09/28 18:53:02 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

long long		ft_abs_long(long long value)
{
	if (value < -9223372036854775807)
		value = value + 1;
	if (value < 0)
		value = (value * -1);
	return (value);
}
