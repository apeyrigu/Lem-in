/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 20:14:59 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/26 20:15:01 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_is_str_next(t_env *env, int i)
{
	if (env->ispreci)
		ft_applywstrpreci(env);
	if (env->flag1 == 0)
		ft_afflargwstr(env);
	while (env->wstr[++i])
	{
		if (env->ispw && env->pw == i)
			break ;
		ft_putwchar(env->wstr[i], env, 0, 0);
	}
	if (env->flag1 == 1)
		ft_afflargwstr(env);
	return (i);
}

static int	ft_is_str(t_env *env, const char *s, int i)
{
	if (env->ispreci && env->preci == 0)
		while (env->largeur--)
		{
			write(1, &env->charflag, 1);
			env->nbrd++;
		}
	else if (!env->wstr)
	{
		env->str = ft_strdup("(null)");
		ft_affstr(env, s);
		ft_memdel((void **)&env->str);
	}
	else
		return (ft_is_str_next(env, i));
	return (-1);
}

static void	ft_is_nb_one_next(t_env *env)
{
	if (env->modifl == 1 || env->convert == 'U' || env->modifz
		|| env->modifj)
		ft_affunb((unsigned long)env->nb, env);
	else if (env->modifl == 2)
		ft_affunb((unsigned long long)env->nb, env);
	else if (env->modifh == 2)
		ft_affunb((unsigned char)env->nb, env);
	else
		ft_affunb((unsigned int)env->nb, env);
}

static void	ft_is_nb_one(t_env *env)
{
	if (ft_strchr("XxOobp\0", env->convert))
		ft_convert(env);
	else if (ft_strchr("Ddi\0", env->convert))
	{
		if (env->modifh == 1 && env->convert != 'D')
			ft_affnb((short)env->nb, env);
		else if (env->modifh == 2 && env->convert != 'D')
			ft_affnb((signed char)env->nb, env);
		else if (env->modifl == 2)
			ft_affnb((long long)env->nb, env);
		else if (env->modifj == 1)
			ft_affnb((intmax_t)env->nb, env);
		else if (env->modifz == 1)
			ft_affnb((ssize_t)env->nb, env);
		else if (env->modifl == 1 || env->convert == 'D')
			ft_affnb((long)env->nb, env);
		else
			ft_affnb((int)env->nb, env);
	}
	else if (ft_strchr("uU\0", env->convert))
		ft_is_nb_one_next(env);
}

int			ft_aff(va_list *ap, t_env *env, const char *s)
{
	int		i;

	i = -1;
	if (env->isnb == 1)
		ft_is_nb_one(env);
	else if (env->c >= 0)
		ft_affchar(env);
	else if (env->convert == 's')
		ft_affstr(env, s);
	else if (env->convert == 'C')
	{
		env->charflag = ' ';
		if (env->flag1 == 0)
			ft_afflarg(env->largeur, 1, env);
		ft_putwchar(env->wchar, env, 0, 0);
		if (env->flag1 == 1)
			ft_afflarg(env->largeur, 1, env);
	}
	else if (env->convert == 'S')
		i = ft_is_str(env, s, i);
	(void)env;
	(void)ap;
	return (i);
}
