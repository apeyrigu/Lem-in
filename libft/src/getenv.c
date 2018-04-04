/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:54:08 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/13 21:58:22 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_char		ft_getenv(char **env)
{
	t_char	res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ft_bzero(&res, sizeof(t_char));
	while (env[i])
		i++;
	res.array = ft_memalloc(sizeof(char *) * i);
	res.size = i;
	i = 0;
	while (env[i])
	{
		while (env[i][j] && env[i][j] != '=')
			j++;
		res.array[i] = ft_strdup(env[i] + (j + 1));
		i++;
		j = 0;
	}
	return (res);
}
