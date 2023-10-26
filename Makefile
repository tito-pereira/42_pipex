# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 14:35:38 by tibarbos          #+#    #+#              #
#    Updated: 2023/10/26 15:08:20 by tibarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf
SRC=
OBJ= ${SRC:.c=.o}
LIB= ./libft/libft.a

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	cd ./libft && make clean
	$(RM) $(OBJ)

fclean: clean
	cd ./libft && make fclean
	$(RM) $(NAME)

re: fclean all
	cd ./libft && make re