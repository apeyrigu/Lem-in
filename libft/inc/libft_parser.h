/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:41:53 by kbensado          #+#    #+#             */
/*   Updated: 2017/05/12 00:37:29 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PARSER_H
# define LIBFT_PARSER_H

# include "./libft.h"
# include "./libft_list.h"
# define D_PARS(funct) ft_pars##funct
# define ADD_NODE_PB(x,y,z,i)(D_LIST(add_back)((t_list**)&x,D_PARS(new)(y,z,i)))
# define PARSE_N(x) ((t_parser *)x->content)->content
# define PARSE_KEY(x) ((t_parser *)x->content)->key
# define PARSE_TYPE(x) ((t_parser *)x->content)->type
# define PARSE_SIZE(x) ((t_parser *)x->content)->content_size

typedef struct		s_parse
{
	void			*content;
	size_t			content_size;
	enum e_type		type;
	char			padding[4];
	size_t			key;

}					t_parser;

int					cmp_pars(size_t a, size_t b, size_t c);
ssize_t				ft_rebuild_quote(t_list *lst, char q[1]);
ssize_t				ft_rebuild_set(t_list *lst, char q[1],
					char w[1], size_t tok);
size_t				ft_nb_quote(t_list *lst, char q[1]);
t_list				*ft_next_quote(t_list *lst, char q[1], bool key);
t_parser			*ft_parsnode(void *content, size_t content_size,
					enum e_type type);
t_list				*ft_parsnew(void *content, size_t content_size,
					enum e_type type);
void				ft_parsset_key(t_list *lst, size_t key);
void				ft_parsprint(t_list *p, bool key);
void				ft_lstremove_if_p(t_list **begin_list, void *data_ref1,
					void *data_ref2, int (*cmp)());
void				ft_parsmorph(t_list **lst, char *new, enum e_type type);

#endif
