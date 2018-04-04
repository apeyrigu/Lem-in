/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 02:42:47 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/25 14:38:06 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_getsconv_nextb(char *s, va_list *ap, t_env *env, int i)
{
	if (*s == 'c' && i == 0)
	{
		env->c = va_arg(*ap, int);
		env->c %= 256;
	}
	else
	{
		if (i == 0)
		{
			env->convert = 'c';
			env->c = *s;
		}
	}
	s++;
	return (s);
}

static char	*ft_getsconv_next(char *s, va_list *ap, t_env *env, int i)
{
	if ((*s == 'C' || (*s == 'c' && env->modifl == 1)) && i == 0)
	{
		env->convert = 'C';
		env->wchar = va_arg(*ap, unsigned int);
		i++;
	}
	else if ((*s == 'S' || (env->modifl && env->convert == 's')) && i == 0)
	{
		env->convert = 'S';
		env->wstr = va_arg(*ap, int*);
		i++;
	}
	return (ft_getsconv_nextb(s, ap, env, i));
}

static char	*ft_getsconv(char *s, va_list *ap, t_env *env, int i)
{
	void *p;

	if (*s == 's' && !env->modifl)
	{
		env->str = va_arg(*ap, char *);
		i++;
	}
	else if (*s == 'p')
	{
		p = va_arg(*ap, void*);
		env->nb = (unsigned long int)p;
		env->isnb = 1;
		i++;
	}
	return (ft_getsconv_next(s, ap, env, i));
}

static char	*ft_getmodif(char *s, va_list *ap, t_env *env)
{
	while (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
	{
		if (*s == 'h')
			env->modifh += 1;
		else if (*s == 'l')
			env->modifl += 1;
		else if (*s == 'j')
			env->modifj = 1;
		else if (*s == 'z')
			env->modifz = 1;
		s++;
	}
	if (!*s)
		return (s);
	env->convert = *s;
	if (*s == 'd' || *s == 'D' || *s == 'u' || *s == 'U' || *s == 'i'
		|| *s == 'x' || *s == 'X' || *s == 'o' || *s == 'O' || *s == 'b')
	{
		env->nb = va_arg(*ap, long);
		env->isnb = 1;
	}
	else
		return (ft_getsconv(s, ap, env, 0));
	s++;
	return (s);
}

char		*ft_getpreci(char *s, va_list *ap, t_env *env)
{
	if (*s != '.')
		return (ft_getmodif(s, ap, env));
	s++;
	env->ispreci = 1;
	if (ft_isdigit(*s))
	{
		env->preci = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
	}
	if (*s == '*')
	{
		env->preci = va_arg(*ap, int);
		s++;
	}
	if (ft_isdigit(*s))
	{
		env->preci = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
	}
	return (ft_getmodif(s, ap, env));
}
