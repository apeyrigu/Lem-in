/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:37:03 by hathor            #+#    #+#             */
/*   Updated: 2017/08/19 03:56:54 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define WS ft_putendl
# define WN ft_putnbrl
# define PRINT ft_printf
# define PRINT_TABC ft_print_tabc
# define PRINT_TABI ft_print_tabi
# define INT_MIN -2147483647
# define INT_MAX 2147483647
# define UINT_MAX 0xFFFFFFFFUL
# define LONG_MAX 0x7FFFFFFFL
# define LONG_MIN 0x80000000L
# define ULONG_MAX 0xFFFFFFFFUL
# define STRING_TEST str[i] == sep[0] || str[i] == sep[1] || str[i] == sep[2]
# define T_CHAR_MALLOC(x, y, z, i) (ft_strsplit_char(x, y, z, 0))
# define T_CHAR_FREE(x) (ft_strsplit_free(x))
# define LEN(x) (ft_strlen(x))
# define MEMDEL(x) (ft_memdel((void *)&x))
# define B_ZERO(x) (ft_bzero(&x, sizeof(x)))
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <sys/param.h>
# include "libft_list.h"
# include "libft_str.h"
# include "libft_parser.h"
# include "libft_malloc.h"
# include "libft_file.h"

typedef struct			s_env
{
	int					flag1;
	int					flag2;
	int					flag3;
	int					flag4;
	char				charflag;
	int					largeur;
	int					preci;
	int					ispreci;
	int					modifh;
	int					modifl;
	int					modifj;
	int					modifz;
	char				convert;
	int					nbrd;
	short int			nbshort;
	long long			nb;
	unsigned long long	unb;
	int					isnb;
	char				*str;
	int					ispw;
	int					pw;
	int					c;
	int					len;
	wchar_t				wchar;
	wchar_t				*wstr;
	char				*base;
}						t_env;

typedef struct			s_int
{
	void				*array;
	void				*size;
	size_t				dimension;
}						t_int;

/*
**	STRINGS
*/

char					*ft_itoa(int n);
char					*ft_random_string(int size);
ssize_t					get_next_line(int fd, char **line);
int						ft_abs_int(int value);
long long				ft_abs_long(long long value);
int						ft_isalpha(int c);
double					ft_atol(char *str);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_isalnum(int c);
int						ft_nbr_len(long nbr);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_atoi(char *str);
int						ft_memcmp(void *s1, void *s2, size_t n);
int						ft_strncmp(char *s1, char *s2, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memccpy(void *dest, void *src, int c, size_t n);
void					*ft_memchr(void *s, int c, size_t n);
void					*ft_memcpy(void *dst, void *src, size_t n);
void					*ft_memdup(void *src, size_t n);
void					*ft_memmove(void *dst, void *src, size_t len);
int						ft_str_is_uppercase(char *str);
bool					ft_str_is_alphanum(char *str, bool key);
size_t					ft_strlcat(char *dst, char *src, size_t n);
size_t					ft_strlcpy(char *dst, char *src, size_t n);
char					*ft_strnstr(char *s1, char *s2, size_t n);
void					*ft_memalloc(size_t size);
int						**ft_memalloctab(size_t w, size_t l);
void					ft_memdel(void **ap);
void					ft_strdel(char **as);
void					ft_putendl(char *s);
void					ft_putnbr(int nb);
void					ft_putnbrl(int nb);
void					ft_print_tab(int *tab, int nb);
void					ft_print_tabc(char **str, size_t len);
void					ft_print_tabi(int **tab, size_t w, size_t l);
void					ft_putstr(char *str);
int						ft_rec_pow(int nb, int power);
int						ft_ite_pow(int nb, int power);
void					ft_sort_integer_tab(int *tab, int size);
int						ft_sqrt(int nb);
int						match(char *s1, char *s2);
void					ft_del_tab(char **tab, size_t len);
void					ft_strclr(char *s);
char					*ft_strdup(char *s1);
char					*ft_strndup(char *s1, size_t n);
int						ft_strequ(char *s1, char *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f) (size_t, char *));
int						ft_strnequ(char *s1, char *s2, size_t n);
char					*ft_strtrim(char *s);
void					ft_swap(int *a, int *b);
void					ft_swap_char(char **a, char **b);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);

/*
**	Contains
*/

bool					ft_contains_int(int *src, int target, size_t len);
bool					ft_contains_str(char **src, char *target);
int						ft_contains_int_at(int *src, int target, size_t len);
int						ft_contains_char_at(char **src, char *target,
						size_t len);
bool					ft_contains_char(char *src, char target);
int						ft_contains_str_at(char **src, char *target,
						size_t len);

/*
**	Convert
*/

void					*ft_malloc(size_t size);
char					*ft_llutoa(long long unsigned n);

void					ft_affchar(t_env *env);
void					ft_affunb(unsigned long long nb, t_env *env);
char					*ft_getflag(char *s, va_list *ap, t_env *env);
char					*ft_getpreci(char *s, va_list *ap, t_env *env);
void					ft_affnb(long long nb, t_env *env);
void					ft_affstr(t_env *env, const char *s);
int						ft_affelem(t_env *env);
void					ft_afflargnb(int larg, int size, t_env *env);
void					ft_afflarg(int larg, int size, t_env *env);
int						ft_putwchar_next(char a, wchar_t
						wchar, char *str, int nb);
void					ft_affo(t_env *env);
void					ft_affp(t_env *env);
void					ft_affx(t_env *env);
char					*ft_llongtoa(long long n);
void					ft_convert(t_env *env);
void					ft_affconv(t_env *env);
int						ft_max(int a, int b, int c);
void					final_len(t_env *list, int len, int preci, int largeur);
int						ft_printf(char const *s, ...);
char					*ft_getflag(char *s, va_list *ap, t_env *env);
int						ft_aff(va_list *ap, t_env *env, char const *s);
int						ft_putwchar(wchar_t wchar, t_env *env, char a, char b);
int						ft_wcharlen(wchar_t wchar, t_env *env, int i);
void					ft_applywstrpreci(t_env *env);
void					ft_afflargwstr(t_env *env);

void					*ft_calloc(size_t num, size_t nsize);
void					*ft_realloc(void *ptr, size_t size);
void					ft_free(void *ptr);

#endif
