/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 00:02:24 by kbensado          #+#    #+#             */
/*   Updated: 2017/03/17 08:01:53 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_data
{
	int				fd_saved;
	char			padding[4];
	char			*data;
}					t_data;

ssize_t				get_next_line(int const fd, char **line);

#endif
