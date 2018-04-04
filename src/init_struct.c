/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 03:12:17 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/29 00:33:41 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		ft_error_pars(int i)
{
	(void)i;
	ft_printf("ERROR\n");
	exit(0);
}

void		ft_check_room(t_lem *lm)
{
	t_list	*tmp;

	tmp = lm->room->next;
	while (tmp)
	{
		if (ft_strcmp(((t_room *)lm->room->content)->name,
			((t_room *)tmp->content)->name) == 0)
			ft_error_pars(14);
		if ((((t_room *)lm->room->content)->x == ((t_room *)tmp->content)->x) &&
			(((t_room *)lm->room->content)->y == ((t_room *)tmp->content)->y))
			ft_error_pars(15);
		tmp = tmp->next;
	}
}

t_room		*ft_init_room(char **str, t_lem *lm, size_t i)
{
	t_room	*tmp;

	tmp = ft_memalloc(sizeof(t_room));
	i = 0;
	if (str[0] == NULL || str[1] == NULL || str[2] == NULL
	|| str[3] != NULL || str[0][0] == 'L')
		ft_error_pars(16);
	tmp->name = ft_strdup(str[0]);
	while (str[1][i] >= '0' && str[1][i] <= '9')
		i++;
	ft_strlen(str[1]) == i ? tmp->x = ft_atoi(str[1]) : ft_error_pars(11);
	i = 0;
	while (str[2][i] >= '0' && str[2][i] <= '9')
		i++;
	ft_strlen(str[2]) == i ? tmp->y = ft_atoi(str[2]) : ft_error_pars(12);
	lm->state == 1 ? lm->start = ft_strdup(str[0]) : (void)i;
	lm->state == 2 ? lm->end = ft_strdup(str[0]) : (void)i;
	lm->state == 2 ? lm->over = lm->nb : (void)i;
	lm->state = 0;
	tmp->nb_name = lm->nb;
	lm->nb++;
	return (tmp);
}
