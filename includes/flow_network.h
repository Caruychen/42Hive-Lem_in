/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:28:29 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 16:54:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *   Flow Network is an adjacency list implementation, representing the whole
 *   ant nest graph.
 *   
 *   It is simply implemented as a vector (dynamic array), with each element
 *   being a node of the rooms. The rooms are numbered according to their index
 *   in the vector, and are thus implicitly numbered by insertion order.
 *  
 *   The t_vec data type is sufficient to represent the flow network graph.
 *   data structure looks a bit like this:
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
 *                                       Edges between rooms have duplicates
 *                                       between corresponding rooms. 
 *                                       both point to the same edge object,
 *                                       so are NOT copies.
*/

#ifndef FLOW_NETWORK_H
# define FLOW_NETWORK_H

# include "flow.h"
# include "bfs.h"
# include "pathset.h"

int			network_init(t_flow_network *network);
int			network_add_node(t_flow_network *network, char *alias,
				int x, int y);
int			network_add_edge(t_flow_network *network, t_flow_edge *edge);
t_flow_node	*network_get(t_flow_network *network, size_t index);
void		network_free(t_flow_network *network);

int			network_has_augmenting_path(t_flow_network *network,
				t_bfs_utils *bfs_utils);
int			network_augment(t_flow_network *network, t_trace trace);
t_pathset	network_export_pathset(t_flow_network *network,
				t_bfs_utils *bfs_utils);

void		edge_free(t_flow_edge **edge);
int			edge_list_make(t_vec *edge_list);
int			edge_list_push(t_vec *edge_list, t_flow_edge *edge);
void		edge_list_free(t_vec *edge_list);
t_flow_edge	*edge_list_get(t_vec *edge_list, size_t index);

#endif
