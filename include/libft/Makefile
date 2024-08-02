# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 16:50:54 by tibarbos          #+#    #+#              #
#    Updated: 2024/08/02 15:28:18 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

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
SRC = ./src/ft_atoi.c \
	  ./src/ft_bzero.c \
	  ./src/ft_calloc.c \
	  ./src/ft_isalnum.c \
	  ./src/ft_isalpha.c \
	  ./src/ft_isascii.c \
	  ./src/ft_isdigit.c \
	  ./src/ft_isprint.c \
	  ./src/ft_itoa.c \
	  ./src/ft_memchr.c \
	  ./src/ft_memcmp.c \
	  ./src/ft_memcpy.c \
	  ./src/ft_memmove.c \
	  ./src/ft_memset.c \
	  ./src/ft_putchar_fd.c \
	  ./src/ft_putendl_fd.c \
	  ./src/ft_putnbr_fd.c \
	  ./src/ft_putstr_fd.c \
	  ./src/ft_split.c \
	  ./src/ft_strchr.c \
	  ./src/ft_strdup.c \
	  ./src/ft_striteri.c \
	  ./src/ft_strjoin.c \
	  ./src/ft_strlcat.c \
	  ./src/ft_strlcpy.c \
	  ./src/ft_strlen.c \
	  ./src/ft_strmapi.c \
	  ./src/ft_strncmp.c \
	  ./src/ft_strnstr.c \
	  ./src/ft_strrchr.c \
	  ./src/ft_strtrim.c \
	  ./src/ft_substr.c \
	  ./src/ft_tolower.c \
	  ./src/ft_toupper.c
OBJDIR= ./obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

BONUS_SRC = ./src/ft_lstnew.c \
		  ./src/ft_lstadd_front.c \
		  ./src/ft_lstsize.c \
		  ./src/ft_lstlast.c \
		  ./src/ft_lstadd_back.c \
		  ./src/ft_lstdelone.c \
		  ./src/ft_lstclear.c \
		  ./src/ft_lstiter.c \
		  ./src/ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:%.c=$(OBJDIR)/%.o)

.PHONY: all bonus clean fclean re

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(BLUE)libft: $(GREEN)library compiled$(WHITE)"

all: $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	@$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "$(BLUE)libft: $(GREEN)library bonus compiled$(WHITE)"

clean:
	@$(RM) $(OBJDIR)
	@echo "$(BLUE)libft: $(RED)object files removed$(WHITE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)libft: $(RED)library and object files removed$(WHITE)"

re: fclean all
