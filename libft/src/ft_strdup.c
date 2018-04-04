/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 12:19:18 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/23 14:00:01 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strndup(char *s1, size_t n)
{
	size_t	i;
	size_t	len;
	char	*dst;

	i = 0;
	len = 0;
	dst = NULL;
	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (len > n)
		len = n;
	dst = ft_strnew(len);
	ft_bzero(dst, len);
	while (i < len && n)
	{
		dst[i] = s1[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(char *s1)
{
	size_t	i;
	size_t	len;
	char	*dst;

	i = 0;
	len = 0;
	dst = NULL;
	if (s1 == NULL)
		return (NULL);
	while (s1[len])
		len++;
	dst = ft_strnew(len);
	ft_bzero(dst, len);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
