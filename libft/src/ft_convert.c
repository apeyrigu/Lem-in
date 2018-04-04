/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 09:07:57 by kbensado          #+#    #+#             */
/*   Updated: 2016/03/25 13:45:34 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		lenbas(unsigned long long n, unsigned long long base)
{
	int i;

	i = 0;
	while (n >= base)
	{
		i++;
		n /= base;
	}
	return (i + 1);
}

void	ft_convertbase(t_env *env, unsigned long long base)
{
	int i;

	i = -1;
	if (!(env->str = (char *)ft_memalloc(sizeof(char) *
	lenbas(env->unb, base) + 1)))
		return ;
	while (env->unb >= base)
	{
		if (env->unb % base > 9)
			env->str[++i] = (env->unb % base) + ('a' - 10);
		else
			env->str[++i] = (env->unb % base) + '0';
		env->unb /= base;
	}
	if (env->unb % base > 9)
		env->str[++i] = (env->unb % base) + ('a' - 10);
	else
		env->str[++i] = (env->unb % base) + '0';
	env->str[++i] = 0;
	env->str = ft_strrev(env->str);
}

void	ft_convert(t_env *env)
{
	unsigned long long base;

	base = 1;
	if (ft_strchr("Xxp", env->convert))
		base = 16;
	else if (env->convert == 'o' || env->convert == 'O')
		base = 8;
	else
		base = 2;
	if (env->modifl == 1 || env->modifj == 1 || env->convert == 'O')
		env->unb = (unsigned long)env->nb;
	else if (env->modifl == 2 || env->convert == 'p')
		env->unb = (unsigned long long)env->nb;
	else if (env->modifh == 1)
		env->unb = (unsigned short)env->nb;
	else if (env->modifh == 2)
		env->unb = (unsigned char)env->nb;
	else if (env->modifz == 1)
		env->unb = (size_t)env->nb;
	else
		env->unb = (unsigned int)env->nb;
	ft_convertbase(env, base);
	ft_affconv(env);
}
