# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 16:31:16 by scornhol          #+#    #+#              #
#    Updated: 2022/03/19 17:18:42 by scornhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_B		=	checker

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC_M		= 	${shell find ./src_mandatory ./src_common -name "*.c"}
OBJ_M		=	$(patsubst %.c,%.o,$(SRC_M))

SRC_B		= 	${shell find ./src_bonus ./src_common -name "*.c"}
OBJ_B		=	$(patsubst %.c,%.o,$(SRC_B))

LIBFT_DIR	=	./libft
HEADER		=	./includes/push_swap.h
HEADS		=	-I.$(LIBFT_DIR)/libft.h -I$(HEADER)

.PHONY:		all clean fclean re bonus rebonus reclean rebc

%.o:		%.c libft/*.c
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ_M) $(HEADER)
			@make -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) $(HEADS) $(OBJ_M) $(LIBFT_DIR)/libft.a -o $(NAME)
			@echo "\033[32m[$(NAME)] mandatory part compiled.\033[0m"

bonus:		$(NAME_B)

$(NAME_B):	$(OBJ_B) $(HEADER)
			@make -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) $(HEADS) $(OBJ_B) $(LIBFT_DIR)/libft.a -o $(NAME_B)
			@echo "\033[32m[$(NAME_B)] bonus part compiled.\033[0m"

clean:
			@make clean -C $(LIBFT_DIR)
			@$(RM) $(OBJ_M) $(OBJ_B)
			@echo "\033[33m[$(NAME)] removed object files.\033[0m"

fclean:		
			@make clean -C $(LIBFT_DIR)
			@$(RM) $(OBJ_M) $(OBJ_B) $(NAME) $(NAME_B) $(LIBFT_DIR)/libft.a
			@echo "\033[33m[$(NAME)] & [libft.a] removed object and executable files.\033[0m"


re:			fclean all

rebonus:	fclean bonus

norm:		
			norminette

reclean:	fclean all clean

ballc:		all bonus clean

reballc:	fclean ballc
