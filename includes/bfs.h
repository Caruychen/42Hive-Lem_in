/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:35:57 by cchen             #+#    #+#             */
/*   Updated: 2022/07/27 20:17:14 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

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

#endif
