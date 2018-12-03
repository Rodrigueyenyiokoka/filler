# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 15:14:08 by oyenyi-           #+#    #+#              #
#    Updated: 2018/08/20 16:02:19 by oyenyi-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Rodriguez.filler

CC = gcc -o

FLAGS = -Wall -Wextra -Werror

INC = -I ./includes/

LIB = ./libft/

SRC = ./srcs/*.c

RM = rm -rf

$(NAME):
	@make -C $(LIB)
	@$(CC) $(NAME) $(FLAGS) $(SRC) $(INC) -L libft/ -lft
	@echo "-- Player Compiled Successfully --"

all: $(NAME)

clean:
	@make clean -C $(LIB)

fclean:
	@make fclean -C $(LIB)
	@$(RM) $(NAME)
	@echo "-- Player Cleaned --"

re: fclean all
