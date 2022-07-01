# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 11:16:17 by cchen             #+#    #+#              #
#    Updated: 2022/07/01 15:31:13 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test_lem-in

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I../libft -I../includes -I./src

TEST_DIR := ./src
TESTS := $(shell find $(TEST_DIR) -type f | grep -e "\.c$$")

SRC_DIR := ../src
SRCS := $(shell find $(SRC_DIR) -type f | grep -v "\main.c$$")

LIB_DIR := ../libft
LIBFT := $(addprefix $(LIB_DIR), libft.a)
LIB_OBJS = $(shell find $(LIB_DIR) -type f | grep -E "\.o$$")
LINK := -L ../libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(TESTS) $(LIB_OBJS) $(LINK) -o $(@)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

debug: CFLAGS += -g
debug: re

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
