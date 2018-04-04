/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 20:03:34 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/26 20:03:36 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char		*ft_getflag_next(char *s, va_list *ap, t_env *env)
{
	if (ft_isdigit(*s))
	{
		env->largeur = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
	}
	if (*s == '*')
	{
		env->largeur = va_arg(*ap, int);
		s++;
	}
	if (ft_isdigit(*s))
	{
		env->largeur = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
	}
	return (ft_getpreci(s, ap, env));
}

char			*ft_getflag(char *s, va_list *ap, t_env *env)
{
	while (*++s == '-' || *s == ' ' || *s == '+' || *s == '#' || *s == '0')
	{
		if (*s == '-')
			env->flag1 = 1;
		if (*s == '+')
			env->flag2 = 1;
		if (*s == ' ')
			env->flag3 = 1;
		if (*s == '#')
			env->flag4 = 1;
		if (*s == '0')
			env->charflag = '0';
	}
	return (ft_getflag_next(s, ap, env));
}
