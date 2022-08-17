/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:13:21 by cchen             #+#    #+#             */
/*   Updated: 2022/08/17 15:49:51 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOW_H
# define FLOW_H

/* ************************************************************************** */
/*                               FLOW_EDGE                                    */
/******************************************************************************
 *   Flow edge represents the link/tunnel between nodes (i.e. rooms).
 *   Edge capacity is capped at 1, making the "flow" state also a
 *   binary state.
 *
 *   t_flow_edge:
 *    ------------------
 *   | FROM | TO | FLOW |
 *    ------------------
 *****************************************************************************/

typedef struct s_flow_edge
{
	size_t		from;
	size_t		to;
	uint8_t		flow: 1;
}				t_flow_edge;

/* ************************************************************************** */
/*                               FLOW_NODE                                    */
/******************************************************************************
 *   Flow node represents a room of the ant nest network. Each node is an
 *   element of the flow_network adjacency list.
 *   
 *   t_flow_node:
 *    ---------------
 *   | ALIAS | EDGES | 
 *    ---------------
 *      |        |
 *      |       \ /                   
 *      |        --------------------------------
 *      |       | edge_0 | edge_1 | edge_2 | ... | } --> t_vec
 *      |        --------------------------------
 *     \ /                            / \
 *       -----------                   |
 *      | char *str |                  DATA TYPE: t_flow_edge
 *       -----------
 *
 *   The ALIAS holds a string that is the name of the room
 *   The EDGES is a "bag" or vector (dynamic array) of edges, which link to
 *   adjacent rooms.
 *
 *   Additional Data Fields:
 *   * dst_to_start: The Distance to Start node
 *   * dst_to_end: The Distance to End node
 *   * is_free: Is the node free (not on a path)
 *   * is_via_augment: Is node accessed through a non-free node by BFS
 *****************************************************************************/

typedef struct s_flow_node
{
	char	*alias;
	t_vec	edges;
	int		x;
	int		y;
	size_t	dst_to_start;
	size_t	dst_to_end;
	uint8_t	is_free: 1;
	uint8_t	is_via_augment: 1;
}				t_flow_node;

/* ************************************************************************** */
/*                               FLOW_NETWORK                                 */
/******************************************************************************
 *   Flow Network is an adjacency list implementation, representing the whole
 *   ant nest graph.
 * 
 *   index   --------------
 *     0    | ALIAS, EDGES | <-- DATA TYPE: flow_node
 *           --------------        -------------------------
 *     1    | ALIAS, EDGES | ---> | FROM: 1, TO: 2, FLOW: 0 |
 *           --------------        -----------------------------
 *     2    | ALIAS, EDGES | ---> | 2, 5, 0 | 2, N, 1 | 1, 2, 0 | 
 *           --------------        -----------------------------
 *                ..                   ^---------v-------------------
 *           --------------        ------------------------         |
 *     5    | ALIAS, EDGES | ---> | 5, 9, 0 | 2, 5, 0 | ... |       |
 *           --------------        ------------------------         |
 *                ...                                               |
 *           --------------        ---------------                  |
 *     N    | ALIAS, EDGES | ---> | 2, N, 1 | ... |                 |
 *           --------------        ---------------                  |
 *                                                                  |
 *                                       Each edge is duplicated twice in
 *                                       the network. Both are pointers
 *                                       to the same memory location holding
 *                                       the edge. NOT copies.
 *
 *   Additional data fields
 *   source:	Index of Start room
 *   sink:		Index of End room
 *   n_ants:	Total Number of ants
 *****************************************************************************/

typedef struct s_flow_network
{
	t_vec	adj_list;
	t_vec	edge_list;
	size_t	source;
	size_t	sink;
	size_t	n_ants;
}		t_flow_network;

#endif
