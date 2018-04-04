/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 17:55:28 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/26 18:13:19 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_affo_next(t_env *env)
{
	if (env->ispreci == 1 && env->preci > (int)ft_strlen(env->str))
	{
		env->nbrd += env->preci - ft_strlen(env->str);
		while (env->preci-- - (int)ft_strlen(env->str) > 0)
			write(1, "0", 1);
		env->preci++;
	}
	if (env->charflag == ' ' && env->flag4 && ft_strcmp(env->str, "0"))
	{
		write(1, "0", 1);
		env->nbrd++;
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

void		ft_affo(t_env *env)
{
	if (!env->flag4 && !ft_strcmp(env->str, "0"))
		env->largeur++;
	else if (env->flag4)
	{
		env->preci--;
		env->largeur--;
	}
	if (env->charflag == '0' && env->flag4 && ft_strcmp(env->str, "0"))
	{
		write(1, "0", 1);
		env->nbrd++;
	}
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
	ft_affo_next(env);
}

static void	ft_affp_next(t_env *env)
{
	if (env->ispreci == 1 && env->preci > (int)ft_strlen(env->str))
	{
		env->nbrd += env->preci - ft_strlen(env->str);
		while ((env->preci-- - (int)ft_strlen(env->str)) > 0)
			write(1, "0", 1);
		env->preci++;
	}
	if (env->ispreci == 1 && env->preci == 0)
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

void		ft_affp(t_env *env)
{
	env->largeur -= 2;
	if (env->preci > (int)ft_strlen(env->str))
		env->largeur -= env->preci;
	else
		env->largeur -= (int)ft_strlen(env->str);
	if (env->largeur < 0)
		env->largeur = 0;
	if (env->charflag == '0')
	{
		write(1, "0x", 2);
		env->nbrd += 2;
	}
	if (!env->flag1)
		while (env->largeur--)
		{
			write(1, &env->charflag, 1);
			env->nbrd++;
		}
	if (env->charflag == ' ')
	{
		write(1, "0x", 2);
		env->nbrd += 2;
	}
	ft_affp_next(env);
}
