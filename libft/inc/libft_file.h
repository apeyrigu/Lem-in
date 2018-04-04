/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 21:34:12 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/27 17:25:53 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FILE_H
# define LIBFT_FILE_H

# include "./libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_file
{
	char			*ptr;
	struct stat		file;
	int				fd;

}					t_fd;

bool				dir_exist(char *path, DIR *buff);
bool				create_dir(char *path);
int					create_file(char *path, bool del);
t_fd				get_file(char *path, size_t len);
void				rm_file(char *path);
bool				execv_it(int in, bool fd, t_char av);
char				*real_pwd_file(char *path, char *res, char *tpwd);
char				*trunc_path_file(char *path);

#endif
