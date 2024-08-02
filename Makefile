# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 14:35:38 by tibarbos          #+#    #+#              #
#    Updated: 2024/08/02 19:07:08 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex

# Compiler && Tools
CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf

# Output colors
RED= \e[31m
GREEN= \e[32m
BLUE= \e[34m
WHITE= \e[37m

# Source && Object Files
SRC= ./src/mandatory/m_free.c \
	./src/mandatory/m_in_out.c ./src/mandatory/m_proc.c \
	./src/mandatory/m_which.c
MAN= ./src/mandatory/m_main.c
BON= ./src/extra/main_bonus.c ./src/extra/proc_bonus.c
OBJDIR= ./obj
S_OBJ= $(SRC:%.c=$(OBJDIR)/%.o)
M_OBJ= $(MAN:%.c=$(OBJDIR)/%.o)
B_OBJ= $(BON:%.c=$(OBJDIR)/%.o)

# Includes
LIB= ./include/libft/libft.a
LFT= -L./include/libft -lft -L./include/ft_printf -lftprintf \
	-L./include/get_next_line -lftgetnextline

.PHONY: all bonus clean fclean re

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(S_OBJ) ${M_OBJ}
	@make -C ./include/libft
	@make -C ./include/ft_printf
	@make -C ./include/get_next_line
	@$(CC) $(CFLAGS) $(S_OBJ) ${M_OBJ} $(LFT) -o $(NAME)
	@echo "$(BLUE)pipex: $(GREEN)program compiled$(WHITE)"

all: $(NAME)

bonus:	fclean $(S_OBJ) $(B_OBJ)
	@make -C ./include/libft
	@make -C ./include/ft_printf
	@make -C ./include/get_next_line
	@$(CC) $(CFLAGS) $(S_OBJ) $(B_OBJ) $(LFT) -o $(NAME)
	@echo "$(BLUE)pipex: $(GREEN)program bonus compiled$(WHITE)"

clean:
	@cd ./include/libft && make -s clean
	@cd ./include/ft_printf && make -s clean
	@cd ./include/get_next_line && make -s clean
	@$(RM) $(OBJDIR)
	@echo "$(BLUE)pipex: $(RED)object files removed$(WHITE)"

fclean: clean
	@cd ./include/libft && make -s fclean
	@cd ./include/ft_printf && make -s fclean
	@cd ./include/get_next_line && make -s fclean
	@$(RM) $(NAME)
	@echo "$(BLUE)pipex: $(RED)program and object files removed$(WHITE)"

re: fclean all
	@cd ./include/libft && make -s re
	@cd ./include/ft_printf && make -s re
	@cd ./include/get_next_line && make -s re
