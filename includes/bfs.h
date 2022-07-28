/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:35:57 by cchen             #+#    #+#             */
/*   Updated: 2022/07/28 11:30:31 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

# include "queue.h"

# define SEARCH_END 1
# define SEARCH_CONTINUE 0

typedef struct s_trace
{
	t_flow_edge	**edge_to;
	t_vec		sink_edges;
}		t_trace;

typedef struct s_bfs_utils
{
	int		*marked;
	t_queue		queue;
	t_trace		trace;
	int		saturate_trace: 1;
}		t_bfs_utils;

int		bfs_init(t_bfs_utils *bfs_utils, t_flow_network *network, int saturate);
int		bfs_search(t_flow_network *network, t_bfs_utils *bfs_utils,
		int (*condition)(t_flow_edge *, size_t, t_vec *));
void	bfs_free(t_bfs_utils *bfs_utils);

#endif
