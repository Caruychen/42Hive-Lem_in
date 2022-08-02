/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:15:55 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 12:08:36 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test(t_flow_network *network, t_pathset best_path)
{
	size_t		index;
	size_t		node_id;
	t_flow_node	*node;
	t_path		*path;

	ft_printf("test\n");
	ft_printf("%ld ants\n", best_path.ants);
	ft_printf("%ld paths\n", best_path.paths.len);
	index = 0;
	while (index < best_path.paths.len)
	{
		path = pathset_get(&best_path, index);
		ft_printf("Path %ld:\n", index);
		ft_printf("%ld nodes\n", path->nodes.len);
		node_id = 0;
		while (node_id < path->nodes.len)
		{
			node = network_get(network,
					*(size_t *)vec_get(&path->nodes, node_id));
			ft_printf("%s, ", node->alias);
			node_id++;
		}
		ft_printf("\n");
		index++;
	}
}

int	is_better(t_pathset pathset)
{
	static size_t	quotient;
	static size_t	remainder;
	size_t			current_q;
	size_t			current_r;
	size_t			res;

	current_q = (pathset.ants + pathset.steps) / pathset.paths.len;
	current_r = (pathset.ants + pathset.steps) % pathset.paths.len;
	res = (!quotient || current_q < quotient
			|| (current_q == quotient && current_r < remainder));
	quotient = current_q * res + quotient * !res;
	remainder = current_r * res + remainder * !res;
	return (res);
}

int	solve(t_flow_network *network, t_pathset *pathset)
{
	t_bfs_utils	bfs_utils;
	t_pathset	best_path;
	t_pathset	tmp_set;

	best_path = (t_pathset){0};
	bfs_init(&bfs_utils, network, 0);
	while (network_has_augmenting_path(network, &bfs_utils))
	{
		network_augment(network, bfs_utils.trace);
		if (pathset_from_network(&tmp_set, network, &bfs_utils) == ERROR)
			return (ERROR);
		if (is_better(tmp_set))
		{
			pathset_free(&best_path);
			best_path = tmp_set;
			continue ;
		}
		pathset_free(&tmp_set);
	}
	*pathset = best_path;
	test(network, best_path);
	return (OK);
}
