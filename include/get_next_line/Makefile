# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 15:55:30 by marvin            #+#    #+#              #
#    Updated: 2024/07/18 15:55:30 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftgetnextline.a

# Compiler && Tools
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

# Output colors
RED= \e[31m
GREEN= \e[32m
BLUE= \e[34m
WHITE= \e[37m

# Source && Object Files
SRC = ./src/get_next_line_utils.c \
      ./src/get_next_line.c
OBJDIR= ./obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

.PHONY: all bonus clean fclean re

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@cd ./include/libft && make -s
	@$(AR) $(NAME) $(OBJ)
	@echo "$(BLUE)libftgetnextline: $(GREEN)library compiled$(WHITE)"

all: $(NAME)

bonus: $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(BLUE)libftgetnextline: $(GREEN)library bonus compiled$(WHITE)"

clean:
	@cd ./include/libft && make -s clean
	@$(RM) $(OBJDIR)
	@echo "$(BLUE)libftgetnextline: $(RED)object files removed$(WHITE)"

fclean: clean
	@cd ./include/libft && make -s fclean
	@$(RM) $(NAME)
	@echo "$(BLUE)libftgetnextline: $(RED)library and object files removed$(WHITE)"

re: fclean all
	@cd ./include/libft && make -s re
