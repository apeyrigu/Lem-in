/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 13:42:47 by kbensado          #+#    #+#             */
/*   Updated: 2015/12/28 12:22:25 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

bool	ft_str_is_alphanum(char *str, bool key)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (!str)
		return (false);
	if (key == true)
		len--;
	while (i < len)
	{
		if (ft_isalpha(str[i]) == 0 && ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}
