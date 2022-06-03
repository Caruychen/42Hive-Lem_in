# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 15:25:03 by cchen             #+#    #+#              #
#    Updated: 2022/06/03 13:55:04 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I./includes -I./includes/libft -I./includes/libft/ft_printf

SRC_DIR := .
OBJ_DIR := .
SUB_DIR := $(shell find $(SRC_DIR) -type d -mindepth 1 -exec basename {} \;) 
SRCS := $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(@)
	mkdir -p $(addprefix $(@)/, $(SUB_DIR))

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
