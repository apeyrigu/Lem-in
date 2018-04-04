/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 01:39:42 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/25 13:51:21 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_applywstrpreci(t_env *env)
{
	int i;

	i = -1;
	env->ispw = 1;
	while (env->wstr[++i])
	{
		if (env->preci - ft_wcharlen(env->wstr[i], env, 0) < 0)
			return ;
		env->preci -= ft_wcharlen(env->wstr[i], env, 0);
		env->pw++;
	}
}

void	ft_afflargwstr(t_env *env)
{
	int i;

	i = -1;
	while (env->wstr[++i])
	{
		if (env->ispw && env->pw == i)
			break ;
		env->largeur -= ft_wcharlen(env->wstr[i], env, 0);
	}
	while (env->largeur-- > 0)
	{
		write(1, &env->charflag, 1);
		env->nbrd++;
	}
}

int		ft_wcharlen(wchar_t wchar, t_env *env, int i)
{
	int nb;

	nb = 0;
	if (wchar < 0x80)
		nb = 1;
	else if (wchar < 0x800)
		nb = 2;
	else if (wchar < 0x10000)
		nb = 3;
	else
		nb = 4;
	if (i == 1)
		env->nbrd += nb;
	return (nb);
}

int		ft_putwchar_next(char a, wchar_t wchar, char *str, int nb)
{
	a |= wchar;
	str[0] = a;
	ft_putstr(str);
	return (nb);
}

int		ft_putwchar(wchar_t wchar, t_env *env, char a, char b)
{
	int				nb;
	int				i;
	char			str[6];

	i = 0;
	nb = ft_wcharlen(wchar, env, 1);
	if (nb == 1)
	{
		write(1, &wchar, 1);
		return (1);
	}
	while (i++ < nb)
	{
		a >>= 1;
		a |= 0x80;
	}
	ft_bzero(str, 5);
	while (nb-- > 1)
	{
		b |= 0x80 | (wchar & 0x0000003f);
		wchar >>= 6;
		str[nb] = b;
		b = 0;
	}
	return (ft_putwchar_next(a, wchar, str, nb));
}
