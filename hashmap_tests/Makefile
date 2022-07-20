# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:12:16 by cchen             #+#    #+#              #
#    Updated: 2022/07/20 15:18:08 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test_hashmap

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I../libft -I./src

TEST_DIR := ./src
TESTS := $(shell find $(TEST_DIR) -type f | grep -e "\.c$$")

LIB_DIR := ../libft
LIBFT := $(addprefix $(LIB_DIR), libft.a)
LIB_OBJS = $(shell find $(LIB_DIR) -type f | grep -E "\.o$$")
LINK := -L ../libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(TESTS) $(LIB_OBJS) $(LINK) -o $(@)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) CFLAGS='$(CFLAGS)'

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
