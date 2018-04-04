/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:43:38 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/25 09:15:17 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_env		ft_init(t_env *env)
{
	env->flag1 = 0;
	env->flag2 = 0;
	env->flag3 = 0;
	env->flag4 = 0;
	env->charflag = ' ';
	env->largeur = 0;
	env->ispreci = 0;
	env->preci = 0;
	env->modifh = 0;
	env->modifl = 0;
	env->modifj = 0;
	env->modifz = 0;
	env->nb = 0;
	env->unb = 0;
	env->isnb = 0;
	env->str = NULL;
	env->wstr = NULL;
	env->pw = 0;
	env->ispw = 0;
	env->len = 0;
	env->c = -1;
	return (*env);
}

static int	ft_printf_next(char const *s, va_list *ap, t_env *env)
{
	while (*s)
	{
		if (*s == '%')
		{
			ft_init(env);
			s = ft_getflag((char *)s, ap, env);
			ft_aff(ap, env, s);
			if (!*s && !env->nbrd)
				return (-1);
		}
		if (*s && *s != '%')
		{
			write(1, s++, 1);
			env->nbrd++;
		}
	}
	return (env->nbrd);
}

int			ft_printf(char const *s, ...)
{
	va_list ap;
	t_env	env;

	if (!s || !*s)
		return (0);
	env.nbrd = 0;
	va_start(ap, s);
	env.nbrd = ft_printf_next(s, &ap, &env);
	if (env.nbrd < 0)
		return (0);
	va_end(ap);
	env.nbrd == 0 ? env.nbrd++ : (env.nbrd = env.nbrd);
	return (env.nbrd);
}
