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
BON=
OBJ= ${SRC:.c=.o}
B_OBJ= ${BON:.c=.o}
LIB= ./libft/libft.a
LFT= -L./libft -lft

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LFT) -o $(NAME)

all: $(NAME)

bonus:	$(B_OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(B_OBJ) $(LFT) -o $(NAME)

clean:
	cd ./libft && make clean
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	cd ./libft && make fclean
	$(RM) $(NAME)

re: fclean all
	cd ./libft && make re