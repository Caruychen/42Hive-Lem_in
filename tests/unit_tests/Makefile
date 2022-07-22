# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 11:16:17 by cchen             #+#    #+#              #
#    Updated: 2022/07/22 14:25:11 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test_lem-in

ROOT := ../..
CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I$(ROOT)/libft -I$(ROOT)/includes -I./src

TEST_DIR := ./src
TESTS := $(shell find $(TEST_DIR) -type f | grep -e "\.c$$")

SRC_DIR := $(ROOT)/src
SRCS := $(shell find $(SRC_DIR) -type f | grep -v "\main.c$$")

LIB_DIR := $(ROOT)/libft
LIBFT := $(addprefix $(LIB_DIR), libft.a)
LIB_OBJS = $(shell find $(LIB_DIR) -type f | grep -E "\.o$$")
LINK := -L $(ROOT)/libft -lft

.PHONY: all debug fsan clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(TESTS) $(LIB_OBJS) $(LINK) -o $(@)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) CFLAGS='$(CFLAGS)'

debug: CFLAGS += -g
debug: re

fsan: CFLAGS += -fsanitize=address -g
fsan: re

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
