/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 23:11:24 by apeyrigu          #+#    #+#             */
/*   Updated: 2017/10/29 00:21:06 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/inc/libft.h"

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	size_t		nb_name;
	size_t		nb_link;
	t_list		*link;
}				t_room;

typedef struct	s_link
{
	char		*name;
	size_t		nb_name;

}				t_link;

typedef struct	s_res
{
	size_t			tab_size;
	size_t			*content;
	struct s_res	*next;

}				t_res;

typedef struct	s_final2
{
	size_t		room;
	size_t		nb;

}				t_final;

typedef struct	s_lem
{
	size_t		size;
	t_list		*room;
	int			state;
	size_t		fourmi;
	size_t		nb_room;
	char		*start;
	char		*end;
	size_t		over;
	t_list		*view;
	t_res		*tab;
	bool		key;
	size_t		nb;
	size_t		*final;
	size_t		j;
	size_t		i;
	bool		command;

}				t_lem;

int				main(void);
t_room			*ft_init_room(char **str, t_lem *lm, size_t i);
void			ft_check_room(t_lem *lm);
int				ft_tube(t_lem *lm, char *str);
void			ft_table_create(t_lem *lm, size_t *temp,
				t_res *check);
void			ft_error_pars(int i);
t_res			*create_node(size_t *content, size_t tab_size);
void			ft_lstadd_back_res(t_res **begin_list, size_t *content,
				size_t tab_size);
void			ft_make_line(t_res	*check, t_lem *lm,
				size_t len);
void			print_link(t_lem *s);
void			ft_print(size_t *tmp, size_t size);
void			final_print(t_lem *lem);
void			free_all(t_lem *s);
void			print_std(t_list *s);
void			ft_found_way(t_lem *lm, t_res *tab);
void			ft_fourmi(t_lem *lm, char *str);
int				ft_comment(t_lem *lm, char *str);
int				ft_room(t_lem *lm, char *str, int i);
bool			ft_comp_tab(t_lem *lm, size_t tmp);
void			del_split(char **split);
char			*get_nm_room(t_lem *s, size_t nb);
t_final			*final_node(size_t nb, size_t room);
void			ft_found_next_link(t_lem *lm, size_t len,
				t_res *line, t_list *tmp);
void			del_split(char **split);

#endif
