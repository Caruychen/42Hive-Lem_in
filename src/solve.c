/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:15:55 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 16:46:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	solve(t_flow_network *network, t_pathset *pathset)
{
	t_bfs_utils	bfs_utils;
	t_pathset	best_path;

	bfs_init(&bfs_utils, network, 0);
	while (network_has_augmenting_path(network, &bfs_utils))
	{
		network_augment(network, bfs_utils.trace);
		best_path = network_export_pathset(network, &bfs_utils);
		if (!best_path.paths.memory)
			return (ERROR);
	}
	*pathset = best_path;
	return (OK);
}
