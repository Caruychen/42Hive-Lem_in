/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:35:57 by cchen             #+#    #+#             */
/*   Updated: 2022/08/17 16:10:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

/* ************************************************************************** */
/*                           BREADTH FIRST SEARCH                             */
/******************************************************************************
 * This BFS sub-function is made to perform basic network searching. Able to
 * perform two types of search.
 *
 * 1. Single path search.
 * 2. Multi path search.
 *
 * Single path search:
 *   Used in the main edmunds-karp algorithm part. Searches for the
 *   first, shortest, augmentable path. Terminates as soon as the end node 
 *   is reached.
 *
 * Multi path search:
 *   Used to extract a path set, containing all the augmented paths with 
 *   flow to the end node. Searches until the entire network is traversed.
 *   Will result in the edge_to and sink_edges array are saturated.
 *****************************************************************************/

# include "queue.h"
# define SEARCH_END 1
# define SEARCH_CONTINUE 0

/*
 * TRACE
 * edge_to: An array with size N = Number of nodes. 
 *    Indexes corresponds to the respective node's index. Each element is
 *    the corresponding edge that points to the respective node.
 *
 * sink_edges: A vector holding all the edges pointing to the end node.
*/

typedef struct s_trace
{
	t_flow_edge	**edge_to;
	t_vec		sink_edges;
}		t_trace;

/* BFS UTILITIES */
typedef struct s_bfs_utils
{
	int			*marked;
	t_queue		queue;
	t_trace		trace;
	int			saturate_trace: 1;
}		t_bfs_utils;

/* BFS UTILITY FUNCTIONS */
int		bfs_init(t_bfs_utils *bfs_utils, t_flow_network *network, int saturate);
int		bfs_reset(t_bfs_utils *bfs_utils, t_flow_network *network);
void	bfs_free(t_bfs_utils *bfs_utils);

/* BFS SEARCH FUNCTION */
int		bfs_search(t_flow_network *network, t_bfs_utils *bfs_utils,
			int (*condition)(t_flow_edge *, size_t, t_vec *));

#endif
