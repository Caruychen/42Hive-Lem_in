/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_network.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:28:29 by cchen             #+#    #+#             */
/*   Updated: 2022/07/23 11:33:52 by cchen            ###   ########.fr       */
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

typedef struct	s_flow_network
{
	t_vec	adj_list;
	t_vec	edge_list;
}		t_flow_network;

int		network_init(t_flow_network *network);
int		network_add_node(t_flow_network *network, char *alias, int x, int y);
int		network_add_edge(t_flow_network *network, t_flow_edge *edge);
void	network_free(t_flow_network *network);

#endif
