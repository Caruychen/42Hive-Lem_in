# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 10:56:18 by cchen             #+#    #+#              #
#    Updated: 2022/08/11 16:01:22 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I./libft -I./includes

SRC_DIR := ./src
SRCS := $(SRC_DIR)/main.c
SRCS += $(SRC_DIR)/cleanup.c
SRCS += $(SRC_DIR)/flow_edge.c
SRCS += $(SRC_DIR)/flow_network.c
SRCS += $(SRC_DIR)/flow_node.c
SRCS += $(SRC_DIR)/flow_network_edge_list.c
SRCS += $(SRC_DIR)/flow_network_augment.c
SRCS += $(SRC_DIR)/parse.c
SRCS += $(SRC_DIR)/parse_ant_number.c
SRCS += $(SRC_DIR)/parse_room.c
SRCS += $(SRC_DIR)/parse_link.c
SRCS += $(SRC_DIR)/parse_utils.c
SRCS += $(SRC_DIR)/queue.c
SRCS += $(SRC_DIR)/bfs.c
SRCS += $(SRC_DIR)/bfs_search.c
SRCS += $(SRC_DIR)/path.c
SRCS += $(SRC_DIR)/pathset.c
SRCS += $(SRC_DIR)/print.c
SRCS += $(SRC_DIR)/print_utils.c
SRCS += $(SRC_DIR)/print_analysis.c
SRCS += $(SRC_DIR)/pathset_solve_tools.c
SRCS += $(SRC_DIR)/solve.c
SRCS += $(SRC_DIR)/options.c

OBJ_DIR := ./obj
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB_DIR := ./libft
LIBFT := $(addprefix $(LIB_DIR), libft.a)
LIB_OBJS = $(shell find $(LIB_DIR) -type f | grep -E "\.o$$")
LINK := -L ./libft -lft

.PHONY: all debug fsan clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_OBJS) $(LINK) -o $(@)

$(OBJ_DIR):
	@mkdir -p $(@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) CFLAGS='$(CFLAGS)'

debug: CFLAGS += -g
debug: clean $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_OBJS) $(LINK) -o $(NAME)

fsan: CFLAGS += -fsanitize=address -g
fsan: clean $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_OBJS) $(LINK) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
