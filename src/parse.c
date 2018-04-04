/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 01:33:30 by kbensado          #+#    #+#             */
/*   Updated: 2017/10/28 02:22:34 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			ft_comment(t_lem *lm, char *str)
{
	if (lm->command == true)
		ft_error_pars(0);
	if (str[0] == 'L')
		ft_error_pars(11);
	if (ft_strcmp(str, "##start") == 0)
		lm->start == NULL ? lm->state = 1 : ft_error_pars(7);
	if (ft_strcmp(str, "##end") == 0)
		lm->end == NULL ? lm->state = 2 : ft_error_pars(8);
	ft_lstadd_back(&lm->view, ft_lstnew((void *)str,
	sizeof(char) * ft_strlen(str) + 1));
	ft_memdel((void*)&str);
	lm->command = true;
	return (0);
}

int			ft_room(t_lem *lm, char *str, int i)
{
	char	**tmp;
	t_room	*temp;

	(void)i;
	if (lm->key == true)
		return (-1);
	tmp = ft_strsplit(str, ' ');
	temp = ft_init_room(tmp, lm, 0);
	ft_lstadd(&lm->room, ft_lstnew((void*)temp, sizeof(t_room)));
	ft_check_room(lm);
	del_split(tmp);
	ft_memdel((void *)&temp);
	lm->command = false;
	return (0);
}

void		ft_fourmi(t_lem *lm, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (ft_strlen(str) == i)
		lm->fourmi = ft_atoi(str);
	if (lm->fourmi <= 0)
		ft_error_pars(0);
}

void		del_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		ft_memdel((void *)&split[i]);
		i++;
	}
	ft_memdel((void *)&split[i]);
	ft_memdel((void *)&split);
}

bool		ft_comp_tab(t_lem *lm, size_t tmp)
{
	t_res	*tab;
	size_t	i;

	i = 0;
	tab = lm->tab;
	while (tab)
	{
		while (i != tab->tab_size)
		{
			if (tab->content[i] == tmp)
				return (false);
			i++;
		}
		i = 0;
		tab = tab->next;
	}
	return (true);
}
