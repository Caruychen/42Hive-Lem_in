/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:12:34 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 23:08:39 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	pathset_init(t_pathset *pathset, size_t n_paths, size_t n_ants)
{
	t_path	path;

	if (vec_new(&pathset->paths, n_paths, sizeof(t_path)) == ERROR)
		return (ERROR);
	while (n_paths > 0)
	{
		if (path_new(&path) == ERROR)
			return (pathset_free(pathset), ERROR);
		if (vec_push(&pathset->paths, &path) == ERROR)
			return (ERROR);
		n_paths--;
	}
	pathset->ants = n_ants;
	pathset->steps = 0;
	return (OK);
}

int	pathset_fill(t_pathset *pathset, t_trace trace)
{
	size_t	index;
	t_path	*path;

	index = 0;
	while (index < trace.sink_edges.len)
	{
		path = pathset_get(pathset, index);
		if (path_fill(path, index, trace) == ERROR)
			return (ERROR);
		index++;
	}
	return (OK);
}

int	pathset_from_network(t_pathset *pathset, t_flow_network *network,
		t_bfs_utils *bfs_utils)
{
	t_trace		trace;

	bfs_utils->saturate_trace = TRUE;
	bfs_search(network, bfs_utils, &edge_has_flow_to);
	trace = bfs_utils->trace;
	if (pathset_init(pathset, trace.sink_edges.len, network->n_ants) == ERROR)
		return (ERROR);
	if (pathset_fill(pathset, trace) == ERROR)
		return (pathset_free(pathset), ERROR);
	return (OK);
}

t_path	*pathset_get(t_pathset *pathset, size_t index)
{
	return ((t_path *) vec_get(&pathset->paths, index));
}

void	pathset_free(t_pathset *pathset)
{
	size_t	index;
	t_path	*path;

	index = 0;
	while (index < pathset->paths.len)
	{
		path = (t_path*) vec_get(&pathset->paths, index);
		vec_free(&path->nodes);
		index++;
	}
	vec_free(&pathset->paths);
}
