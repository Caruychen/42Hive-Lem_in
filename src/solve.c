/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:15:55 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 16:38:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_better(t_pathset pathset)
{
	static size_t	quotient;
	static size_t	remainder;
	size_t			current_q;
	size_t			current_r;
	size_t			res;

	current_q = (pathset.ants + pathset.total_nodes) / pathset.paths.len;
	current_r = (pathset.ants + pathset.total_nodes) % pathset.paths.len;
	res = (!quotient || current_q < quotient
			|| (current_q == quotient && current_r < remainder));
	quotient = current_q * res + quotient * !res;
	remainder = current_r * res + remainder * !res;
	return (res);
}

void	select_paths(t_pathset *pathset)
{
	static t_pathset	best;

	if (is_better(*pathset))
	{
		pathset_free(&best);
		best = *pathset;
		return ;
	}
	pathset_free(pathset);
	*pathset = best;
}

void	trim_paths(t_pathset *pathset)
{
	size_t	quotient;
	t_path	path;

	if (!pathset || !pathset->paths.len)
		return ;
	while (1)
	{
		quotient = (pathset->ants + pathset->total_nodes) / pathset->paths.len;
		if (quotient > pathset_get(pathset, pathset->paths.len - 1)->height)
			break ;
		while (quotient <= pathset_get(pathset, pathset->paths.len - 1)->height)
		{
			vec_pop(&path, &pathset->paths);
			pathset->total_nodes -= path.height;
			path_free(&path);
		}
	}
	pathset->steps = quotient;
}

void	assign_ants(t_pathset *pathset)
{
	size_t	ants;
	size_t	index;
	size_t	len;
	size_t	remainder;
	t_path	*path;

	ants = pathset->ants;
	len = pathset->paths.len;
	remainder = (ants + pathset->total_nodes) % len;
	pathset->steps += remainder > 0;
	index = 0;
	while (index < len)
	{
		path = pathset_get(pathset, index++);
		path->ants = (pathset->steps - (remainder <= 0)) - path->height;
		remainder -= remainder > 0;
		ants -= path->ants;
	}
}

int	solve(t_flow_network *network, t_pathset *pathset)
{
	t_bfs_utils	bfs_utils;

	bfs_init(&bfs_utils, network, 0);
	while (network_has_augmenting_path(network, &bfs_utils))
	{
		network_augment(network, bfs_utils.trace);
		if (pathset_from_network(pathset, network, &bfs_utils) == ERROR)
			return (ERROR);
		select_paths(pathset);
	}
	trim_paths(pathset);
	assign_ants(pathset);
	bfs_free(&bfs_utils);
	return (OK);
}
