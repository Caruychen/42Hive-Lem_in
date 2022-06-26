# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 10:56:18 by cchen             #+#    #+#              #
#    Updated: 2022/06/26 13:56:55 by carlnysten       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I./libft -I./includes

SRC_DIR := ./src
SRCS := $(SRC_DIR)/main.c
SRCS += $(SRC_DIR)/parse.c
SRCS += $(SRC_DIR)/cleanup.c
SRCS += $(SRC_DIR)/get_ant_number.c
SRCS += $(SRC_DIR)/get_room.c
SRCS += $(SRC_DIR)/get_link.c

OBJ_DIR := ./obj
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB_DIR := ./libft
LIBFT := $(addprefix $(LIB_DIR), libft.a)
LIB_OBJS = $(shell find $(LIB_DIR) -type f | grep -E "\.o$$")
LINK := -L ./libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_OBJS) $(LINK) -o $(@)

$(OBJ_DIR):
	@mkdir -p $(@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

debug: CFLAGS += -g
debug: clean $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_OBJS) $(LINK) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
