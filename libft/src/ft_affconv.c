/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 09:49:22 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/25 14:43:33 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_affx_nextb(t_env *env)
{
	if (env->ispreci == 1 && env->preci > (int)ft_strlen(env->str))
	{
		env->nbrd += env->preci - ft_strlen(env->str);
		while (env->preci-- - (int)ft_strlen(env->str) > 0)
			write(1, "0", 1);
		env->preci++;
	}
	if (env->ispreci == 1 && !env->preci)
		;
	else
	{
		ft_putstr(env->str);
		env->nbrd += (int)ft_strlen(env->str);
	}
	if (env->flag1)
		while (env->largeur--)
		{
			write(1, &env->charflag, 1);
			env->nbrd++;
		}
}

static void	ft_affx_next(t_env *env)
{
	if (env->preci > (int)ft_strlen(env->str))
		env->largeur -= env->preci;
	else
		env->largeur -= (int)ft_strlen(env->str);
	if (env->largeur < 0)
		env->largeur = 0;
	if (!env->flag1)
		while (env->largeur--)
		{
			write(1, &env->charflag, 1);
			env->nbrd++;
		}
	if (env->charflag == ' ' && env->flag4 && ft_strcmp("0", env->str))
	{
		write(1, "0", 1);
		write(1, &env->convert, 1);
		env->nbrd += 2;
	}
	ft_affx_nextb(env);
}

void		ft_affx(t_env *env)
{
	if (!ft_strcmp("0", env->str))
		env->largeur++;
	if (env->flag4 && ft_strcmp("0", env->str))
		env->largeur -= 2;
	if (env->charflag == '0' && env->flag4 && ft_strcmp("0", env->str))
	{
		write(1, "0", 1);
		write(1, &env->convert, 1);
		env->nbrd += 2;
	}
	ft_affx_next(env);
}

void		ft_affconv(t_env *env)
{
	if (env->convert == 'X')
		ft_strupcase(env->str);
	if (env->flag1)
		env->charflag = ' ';
	if (env->convert == 'x' || env->convert == 'X')
	{
		ft_affx(env);
		ft_free(env->str);
	}
	if (env->convert == 'o' || env->convert == 'O')
	{
		ft_affo(env);
		ft_free(env->str);
	}
	if (env->convert == 'p')
	{
		ft_affp(env);
		ft_free(env->str);
	}
}
