/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 09:36:52 by kbensado          #+#    #+#             */
/*   Updated: 2016/11/27 02:00:30 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int					match(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s1 == *s2 && *s1 != '*')
		return (match(s1 + 1, s2 + 1));
	else if (*s1 == '*' && *s2 == '*')
		return (match(s1 + 1, s2));
	else if (*s2 == '*' && !*s1)
		return (match(s1, s2 + 1));
	else if (*s2 == '*' && *s2 && *s1)
		return (match(s1, s2 + 1) || match(s1 + 1, s2));
	else
		return (0);
}
