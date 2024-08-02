# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 16:57:08 by tibarbos          #+#    #+#              #
#    Updated: 2024/08/02 15:34:29 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

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
SRC = ./src/central.c \
      ./src/death_star.c \
      ./src/n_utils_1.c \
	  ./src/n_utils_2.c \
	  ./src/n_utils_3.c \
      ./src/n_specs_1.c \
	  ./src/n_specs_2.c \
	  ./src/n_hex.c \
	  ./src/n_flag.c \
      ./src/pain_exist.c \
	  ./src/pain_size.c \
	  ./src/pain_checks.c \
	  ./src/p_flag.c \
      ./src/ip_specs_1.c \
	  ./src/ip_specs_2.c \
	  ./src/ip_specs_u.c\
      ./src/p_specs_r1.c \
	  ./src/p_specs_r2.c \
	  ./src/p_specs_l1.c \
	  ./src/p_specs_l2.c \
      ./src/ft_itoa.c \
	  ./src/ft_long_itoa.c \
	  ./src/ft_hbx_itoa.c \
	  ./src/ft_hx_itoa.c \
	  ./src/ft_lhx_itoa.c
OBJDIR= ./obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

.PHONY: all bonus clean fclean re

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@cd ./include/libft && make -s
	@$(AR) $(NAME) $(OBJ)
	@echo "$(BLUE)libftprintf: $(GREEN)library compiled$(WHITE)"

all: $(NAME)

bonus: $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(BLUE)libftprintf: $(GREEN)library bonus compiled$(WHITE)"

clean:
	@cd ./include/libft && make -s clean
	@$(RM) $(OBJDIR)
	@echo "$(BLUE)libftprintf: $(RED)object files removed$(WHITE)"

fclean: clean
	@cd ./include/libft && make -s fclean
	@$(RM) $(NAME)
	@echo "$(BLUE)libftprintf: $(RED)library and object files removed$(WHITE)"

re: fclean all
	@cd ./include/libft && make -s re
