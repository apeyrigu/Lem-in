
CC = gcc

CFLAG = -Wall -Wextra -Werror -g

NAME = libft.a

INC_PATH =	./inc/

OBJ_PATH = ./obj/

SRC_PATH = ./src/

SRC_NAME =	calloc.c	ft_isspace.c	ft_printf.c             ft_strcmp.c		ft_strsplit_char.c\
free.c                 ft_itoa.c        ft_putchar.c            ft_strcpy.c     ft_strsplit_free.c\
ft_abs_int.c           ft_len_nbr.c     ft_putchar_fd.c         ft_strcute.c    ft_strstr.c\
ft_abs_long.c          ft_llongtoa.c    ft_putendl.c            ft_strdel.c     ft_strsub.c\
ft_aff.c               ft_llutoa.c      ft_putendl_fd.c         ft_strdup.c     ft_strtok.c\
ft_aff2.c              ft_lstadd.c      ft_putnbr.c             ft_strequ.c     ft_strtrim.c\
ft_aff_file.c          ft_lstdel.c      ft_putnbr_fd.c          ft_strisspace.c ft_strupcase.c\
ft_aff_nb.c            ft_lstdelone.c   ft_putnbrl.c            ft_striter.c    ft_swap.c\
ft_aff_p.c             ft_lstiter.c     ft_putstr.c             ft_striteri.c   ft_swap_char.c\
ft_affconv.c           ft_lstmap.c      ft_putstr_fd.c          ft_strjoin.c    dir_macro.c\
ft_affconv2.c          ft_lstnew.c      ft_putwchar.c           ft_strlcat.c    ft_tolower.c\
ft_atoi.c              ft_strlcpy.c	    ft_toupper.c			ft_get_arg_2.c	getenv.c\
ft_atol.c              ft_memalloc.c    ft_rebuild_quote.c      ft_strlen.c     get_next_line.c\
ft_bzero.c             ft_memalloctab.c ft_rebuild_set.c        ft_strlowcase.c handle_size.c\
ft_contains.c          ft_memccpy.c     ft_recursive_power.c    ft_strmap.c     iterate_memory.c\
ft_convert.c           ft_memchr.c      ft_sort_integer_table.c ft_strmapi.c    malloc.c\
ft_convert_list_char.c ft_memcmp.c      ft_sqrt.c               ft_strncat.c    match.c\
ft_del_tab.c           ft_memcpy.c      ft_str_is_alpha.c       ft_strncmp.c    memory_list.c\
ft_get_arg.c           ft_memdel.c      ft_str_is_lowercase.c   ft_strncpy.c    realloc.c\
ft_getflag.c           ft_memmove.c     ft_str_is_numeric.c     ft_strnequ.c    show_alloc_memory.c\
ft_getpars.c           ft_memset.c      ft_str_is_printable.c   ft_strnew.c     tools.c\
ft_isalnum.c           ft_str_is_uppercase.c   					ft_strnstr.c    tools2.c\
ft_isalpha.c           ft_parser.c      ft_strcapitalize.c      ft_strrchr.c	fork_macro.c\
ft_isascii.c           ft_print_tab.c   ft_strcat.c             ft_strrev.c		dir_macro2.c\
ft_isdigit.c           ft_print_tabc.c  ft_strchr.c             ft_strsplit.c	ft_lstadd_insert.c\
ft_isprint.c           ft_print_tabi.c  ft_strclr.c             ft_strsplit2.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC =		$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =		$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "compile done !"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			@mkdir -p $(OBJ_PATH)
			@$(CC) $(CFLAG) -I$(INC_PATH) -o $@ -c $<
clean:
			@rm -rf $(OBJ)
			@echo "clean done !"

fclean:		clean
			@rm -rf $(NAME)
			@echo "fclean done !"

re: 		fclean all


# ft_rebuild_set.c ft_parser.c ft_rebuild_quote.c ft_convert_list_char.c ft_strtok.c ft_strsplit_free.c ft_strsplit_char.c get_next_line.c match.c ft_get_arg.c\
# 			ft_memalloctab.c ft_strsplit2.c ft_del_tab.c ft_print_tabc.c ft_print_tabi.c\
# 			ft_atol.c ft_len_nbr.c ft_strisspace.c ft_strcute.c ft_putnbrl.c ft_isspace.c\
# 			ft_print_tab.c ft_abs_int.c ft_abs_long.c ft_swap_char.c ft_atoi.c ft_isalnum.c\
# 			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_bzero.c ft_itoa.c ft_lstadd.c\
# 			ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c\
# 			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c\
# 			ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_recursive_power.c\
# 			ft_sort_integer_table.c ft_sqrt.c ft_strcapitalize.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c\
# 			ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_numeric.c\
# 			ft_str_is_printable.c ft_str_is_uppercase.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
# 			ft_strlen.c ft_strlowcase.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c\
# 			ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_strupcase.c\
# 			ft_swap.c ft_tolower.c ft_toupper.c ft_contains.c\
# 			calloc.c free.c handle_size.c iterate_memory.c malloc.c memory_list.c realloc.c show_alloc_memory.c tools.c tools2.c\
# 			ft_aff2.c ft_aff_file.c ft_aff_nb.c ft_aff_p.c ft_affconv.c ft_affconv2.c ft_convert.c ft_getflag.c ft_getpars.c ft_llongtoa.c ft_llutoa.c ft_putwchar.c\
# 			ft_printf.c
	

.PHONY: re fclean clean $(NAME) all