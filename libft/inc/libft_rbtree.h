/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_rbtree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 23:27:38 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/20 23:48:02 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_RBTREE_H
# define LIBFT_RBTREE_H

# include "libft.h"

enum		e_color
{
	RED,
	BLACK,
};

typedef	struct	s_rb_node
{
	struct s_rb_node	*parent;
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*data;
	enum e_color		color;
	enum e_type			type;
}				t_rbtree;

t_rbtree		*btree_create_node(void *data, enum e_color color,
				enum e_type type);

#endif
