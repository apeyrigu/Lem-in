/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:58:08 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/26 18:58:10 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int			ft_affelem(t_env *env)
{
	int i;

	i = 0;
	if (env->ispreci == 1)
		env->len = env->preci;
	else
		env->len = ft_strlen(env->str);
	if (env->len < env->largeur)
		env->len = env->largeur - env->preci;
	while (env->len > 0)
	{
		if (env->str[i])
			write(1, &env->str[i], 1);
		else
			write(1, &env->charflag, 1);
		i++;
		env->len--;
	}
	return (i);
}

void		ft_afflarg(int larg, int size, t_env *env)
{
	if (larg > size)
		while (larg-- - size != 0)
		{
			ft_putchar(env->charflag);
			env->nbrd++;
		}
}

void		ft_afflargnb(int larg, int size, t_env *env)
{
	if (larg > size)
		while (larg-- - size != 0)
		{
			if (((env->preci > size && env->preci < larg) || env->preci < 0) ||
				env->ispreci == 0)
				ft_putchar(env->charflag);
			else
				ft_putchar(' ');
			env->nbrd++;
		}
}

static void	ft_affstr_next(t_env *env, char *str)
{
	if (env->ispreci)
		str[env->preci] = '\0';
	if (env->flag1 == 1)
	{
		ft_putstr(str);
		env->nbrd += ft_strlen(str);
		ft_afflarg(env->largeur, ft_strlen(str), env);
		return ;
	}
	ft_afflarg(env->largeur, ft_strlen(str), env);
	ft_putstr(str);
	env->nbrd += ft_strlen(str);
	ft_memdel((void **)&str);
}

void		ft_affstr(t_env *env, const char *s)
{
	char *str;

	if (!env->str || env->str == NULL || !*env->str)
	{
		if (*s && !env->flag3 && !env->flag2 && env->str != NULL)
			return (ft_afflarg(env->largeur, 0, env));
		if (env->flag3 == 1 && env->str != NULL && !env->flag2)
			return (ft_afflarg(env->largeur, 0, env));
		else
			str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(env->str);
	ft_affstr_next(env, str);
}
