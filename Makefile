# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/21 02:48:50 by kbensado          #+#    #+#              #
#    Updated: 2017/10/29 01:28:27 by apeyrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc

CFLAG =			-Wall -Wextra -Werror -g

NAME_N =		lem-in

SRC_PATH_N =	./src/

OBJ_PATH_N =	./obj/

LIBFT_PATH =	./libft/

INC_PATH_N =	./inc/

SRC_NAME_N =	found_way.c main.c init_struct.c tube.c ft_apply.c init_content.c init_new_line.c final_print.c final_print2.c del.c parse.c

OBJ_NAME_N =	$(SRC_NAME_N:.c=.o)

LIBFT_NAME =	libft.a

INC_NAME_N =	lem_in.h

SRC_N =			$(addprefix $(SRC_PATH_N),$(SRC_NAME_N))

OBJ_N =			$(addprefix $(OBJ_PATH_N),$(OBJ_NAME_N))

INC_N =			$(addprefix $(INC_PATH_N),$(INC_NAME_N))

LIBFT =			$(addprefix $(LIBFT_PATH),$(LIBFT_NAME))
INCLIBFT = 		$(LIBFT_PATH)inc

LIBFT_FLAG = 	-L$(LIBFT_PATH) -lft

all:			libft $(NAME_N)				

$(NAME_N):		$(OBJ_N)
				$(CC) $(LIBFT_FLAG) -o $@ $^
				@echo "Done"

$(OBJ_PATH_N)%.o: 	$(SRC_PATH_N)%.c $(INC_N)
					mkdir -p $(OBJ_PATH_N)
					$(CC) $(CFLAG) -I$(INC_PATH_N) -I$(INCLIBFT) -o $@ -c $< 

libft:			$(LIBFT)

$(LIBFT):		$(LIBFT_PATH)
				@make -C $(LIBFT_PATH)

clean:
				@make -C $(LIBFT_PATH) clean
				@rm -f $(OBJ_N)

fclean:			
				@rm -f $(OBJ_N)
				@make -C $(LIBFT_PATH) fclean
				@rm -f $(NAME_N)

re: 			fclean all

.PHONY:			all libft clean fclean re
