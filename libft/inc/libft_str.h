/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 06:24:34 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/27 17:04:44 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H

# include "libft.h"
# include "libft_list.h"
# define ARGN range.array[j][0]?res[c++] = ft_strdup(range.array[j]) : (void)i
# define CAT(...) ft_strultimatecat(__VA_ARGS__)

typedef struct	s_char
{
	char		**array;
	size_t		size;
}				t_char;

/*
**	"inc" for the pos of argc after option
**	"i" for the opt to treat
**	"nb_opt" ...
*/

typedef struct	s_arg
{
	size_t		inc;
	size_t		nb_opt;
	size_t		i;
	t_char		opt;
}				t_arg;

t_char			ft_getenv(char **env);
t_char			ft_list_to_char(t_list *list);
void			del_t_char(t_char *ptr);
t_char			ft_set_arg(size_t len, ...);
size_t			get_nb_arg(int ac, char **av, t_char range, int i);
bool			is_optionw(char *src, t_char range);
t_list			*ft_strtok_list(char *s, char *del, bool add);
void			ft_strsplit_char(char *s, char c, t_char *split, size_t i);
void			ft_strsplit_free(t_char *p);
t_arg			ft_get_arg(char **av, int ac, t_char range, int i);
char			*ft_strsub(char *s, size_t start, size_t len);
size_t			ft_strlen(char *s);
int				ft_str_is_alpha(char *str);
int				ft_strisspace(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strnicmp(char *s1, char *s2, size_t n,
				size_t start);
char			*ft_strchr(char *s, int c);
char			*ft_strcute(char *s, char c);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
char			*ft_strcapitalize(char *str);
char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strstr(char *s1, char *s2);
char			*ft_strncpy(char *dst, char *src, size_t n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strcatdup(char *s1, char *s2);
char			*ft_strcatpath(char *s1, char *s2);
char			*ft_strncat(char *s1, char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strrchr(char *s, int c);
int				ft_isdigit(int c);
char			*ft_strmap(char *s, char (*f)(char));
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strmapi(char *s, char (*f)(size_t, char));
char			*ft_strrev(char *str);
char			**ft_strsplit(char *s, char c);
char			**ft_strsplit2(char *str, char c, char b, char **tab);
t_list			*ft_char_to_list(t_char *src, ssize_t key);
char			*ft_strultimatecat(size_t count, size_t i, size_t len, ...);
char			**ft_strtabnew(size_t count, ...);
char			*ft_strless(char *less, char *src, bool del);

#endif
