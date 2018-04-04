/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 19:08:36 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/26 19:08:38 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_affnb4(long long nb, t_env *env, char *str)
{
	if (env->ispreci == 1 && !ft_strcmp("0", str) && env->preci == 0)
	{
		if (env->charflag == '0' || env->largeur > 1)
		{
			ft_putchar(env->charflag);
			env->nbrd++;
		}
	}
	else
	{
		ft_putstr(str);
		env->nbrd += ft_strlen(str);
	}
	if (env->flag1 == 1)
		ft_afflargnb(env->largeur, ft_strlen(str), env);
	if (nb < 0)
		str--;
	ft_memdel((void **)&str);
}

static void	ft_affnb3(long long nb, t_env *env, char *str)
{
	if (env->charflag == ' ' && (nb < 0 || env->flag2 == 1))
	{
		if (nb < 0)
			ft_putchar('-');
		else if (env->flag2 == 1)
			ft_putchar('+');
		env->nbrd++;
		env->largeur--;
	}
	if (env->ispreci == 1 && env->preci > (int)ft_strlen(str))
	{
		env->nbrd += env->preci - ft_strlen(str);
		while (env->preci-- - ft_strlen(str) > 0)
			write(1, "0", 1);
	}
}

static void	ft_affnb2(long long nb, t_env *env, char *str)
{
	if (env->preci > (int)ft_strlen(str))
		env->largeur -= (env->preci - ft_strlen(str));
	if (env->flag3 == 1 && nb >= 0 && env->flag2 == 0)
	{
		env->largeur--;
		ft_putchar(' ');
		env->nbrd++;
	}
	if (env->flag1 == 0)
	{
		if (nb < 0 && env->charflag == '0')
		{
			env->nbrd++;
			ft_putchar('-');
		}
		if (nb < 0)
			env->largeur--;
		ft_afflargnb(env->largeur, ft_strlen(str), env);
	}
	else
		env->charflag = ' ';
}

void		ft_affnb(long long nb, t_env *env)
{
	char	*str;
	int		abso;

	abso = nb;
	if (nb < 0)
		abso = nb * -1;
	str = ft_llongtoa(nb);
	if (nb < 0)
		str++;
	if (env->flag2 == 1 && nb >= 0 && env->charflag == '0')
	{
		ft_putchar('+');
		env->largeur--;
		env->nbrd++;
	}
	else if (env->flag2 == 1 && nb >= 0 && env->flag1 == 0)
		env->largeur--;
	ft_affnb2(nb, env, str);
	ft_affnb3(nb, env, str);
	ft_affnb4(nb, env, str);
}
