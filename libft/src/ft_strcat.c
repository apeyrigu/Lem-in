/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 13:59:55 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/19 05:11:00 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char			*ft_strcat(char *s1, char *s2)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s1[i])
		i++;
	while (s2[k])
	{
		s1[i] = s2[k];
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}

char			*ft_strultimatecat(size_t count, size_t i, size_t len, ...)
{
	va_list		ap;
	char		**tmp;
	char		*buff;
	char		*res;

	res = NULL;
	va_start(ap, len);
	tmp = ft_memalloc(sizeof(char *) * count);
	while (i < count)
	{
		buff = va_arg(ap, char *);
		tmp[i] = ft_strdup(buff);
		len += ft_strlen(buff);
		i++;
	}
	i = 0;
	res = ft_memalloc(len + 1);
	while (i < count)
	{
		res = ft_strcat(res, tmp[i]);
		i++;
	}
	ft_del_tab(tmp, count);
	return (res);
}

char			*ft_strcatpath(char *s1, char *s2)
{
	size_t		i;
	size_t		k;
	char		*res;

	i = 0;
	k = 0;
	while (s1[i])
		i++;
	while (s2[k])
	{
		k++;
		i++;
	}
	res = ft_strnew(i + 1);
	res = ft_strcat(res, s1);
	res = ft_strcat(res, "/");
	res = ft_strcat(res, s2);
	return (res);
}

char			*ft_strcatdup(char *s1, char *s2)
{
	size_t		i;
	size_t		k;
	char		*res;

	i = 0;
	k = 0;
	res = NULL;
	while (s1[i])
		i++;
	while (s2[k])
	{
		k++;
		i++;
	}
	res = ft_strnew(i + 1);
	res = ft_strcat(res, s1);
	res = ft_strcat(res, s2);
	return (res);
}
