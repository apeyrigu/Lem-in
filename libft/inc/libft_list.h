/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 22:50:00 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/28 07:46:35 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include "libft.h"
# define D_LIST(funct) ft_lst##funct
# define NEW_LIST(x, y) (D_LIST(new)(x, y))
# define ADD_NODE(x,y,z) (D_LIST(add)((t_list**)&x, NEW_LIST(y,z)))
# define ADD_NODE_B(x,y,z) (D_LIST(add_back)((t_list**)&x, NEW_LIST(y,z)))
# define ADD_NODE_F(x,y,z) (D_LIST(add_front)((t_list**)&x, NEW_LIST(y,z)))
# define ADD_NODE_I(x,y,z,c) (D_LIST(add_index)((t_list**)&x,NEW_LIST(y,z),c,0))
# define PRINT_LSIMPLE(x) (D_LIST(print_simple)(x))

enum			e_type
{
	INT,
	CHAR,
	STRING,
	LIST,
	TOKEN,
	QUOTE,
	CONDITION
};

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}				t_list;

t_list			*ft_lstnew(void *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			*ft_lstback(void **lst, void *data);
void			*ft_lstfront(void **lst, void *data);
void			ft_lstclear_n(t_list **begin_list);
void			ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstremove_if(t_list **begin_list, void *data_ref,
				int (*cmp)());
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstprint_simple(t_list *lst);
void			ft_lstadd_index(t_list **begin_list, t_list *new,
				int (*cmp)(void *, void *), size_t i);
void			ft_lstadd_back(t_list **begin_list, t_list *new);
void			ft_lstadd_front(t_list **begin_list, t_list *new);
void			ft_lstremove_if(t_list **begin_list, void *data_ref,
				int (*cmp)());
void			ft_lstsort(t_list **begin_list, int (*cmp)(void*, void*));
size_t			ft_lstsize(t_list *begin_list);
void			ft_lstforeach(t_list *begin_list, void (*f)(void *));
void			ft_lstforeach_if(t_list *begin_list, void (*f)(void *),
				void *data_ref, int (*cmp)());
void			ft_lstmerge(t_list **begin_list1, t_list *begin_list2);

#endif
