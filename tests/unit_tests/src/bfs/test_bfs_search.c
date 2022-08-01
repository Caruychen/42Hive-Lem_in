/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:35:30 by cchen             #+#    #+#             */
/*   Updated: 2022/08/01 14:22:41 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Testing on:
 *     0
 *    /|
 *   1 2-3
 *   | | |
 *   4-5 6
 *     |/
 *     7
 */
#include "unit_test.h"

static void init_dummy_network(t_flow_network *network)
{
	assert(network_init(network) != ERROR);
	assert(network_add_node(network, ft_strdup("0"), 2, 0) != ERROR);
	assert(network_add_node(network, ft_strdup("1"), 0, 2) != ERROR);
	assert(network_add_node(network, ft_strdup("2"), 2, 2) != ERROR);
	assert(network_add_node(network, ft_strdup("3"), 4, 2) != ERROR);
	assert(network_add_node(network, ft_strdup("4"), 0, 4) != ERROR);
	assert(network_add_node(network, ft_strdup("5"), 2, 4) != ERROR);
	assert(network_add_node(network, ft_strdup("6"), 4, 4) != ERROR);
	assert(network_add_node(network, ft_strdup("7"), 2, 6) != ERROR);
	assert(network_add_edge(network, edge_make(0, 1)) != ERROR);
	assert(network_add_edge(network, edge_make(0, 2)) != ERROR);
	assert(network_add_edge(network, edge_make(1, 4)) != ERROR);
	assert(network_add_edge(network, edge_make(2, 3)) != ERROR);
	assert(network_add_edge(network, edge_make(2, 5)) != ERROR);
	assert(network_add_edge(network, edge_make(4, 5)) != ERROR);
	assert(network_add_edge(network, edge_make(3, 6)) != ERROR);
	assert(network_add_edge(network, edge_make(5, 7)) != ERROR);
	assert(network_add_edge(network, edge_make(6, 7)) != ERROR);
	network->source = 0;
	network->sink = 7;
}

static void	first_search(t_flow_network *network, t_bfs_utils *bfs_utils)
{
	t_trace			*trace;

	trace = &bfs_utils->trace;
	assert(bfs_search(network, bfs_utils, &edge_has_residual_capacity_to));
	assert(trace->sink_edges.len == 0);
	assert(edge_other(trace->edge_to[7], 7) == 5);
	assert(edge_other(trace->edge_to[5], 5) == 2);
	assert(edge_other(trace->edge_to[2], 2) == 0);
}

static void	first_augment(t_flow_network *network, t_trace trace)
{
	assert(edge_augment_flow_to(trace.edge_to[7], 7, network));
	assert(edge_augment_flow_to(trace.edge_to[5], 5, network));
	assert(edge_augment_flow_to(trace.edge_to[2], 2, network));
}

static void	second_search(t_flow_network *network, t_bfs_utils *bfs_utils)
{
	t_trace	*trace;

	trace = &bfs_utils->trace;
	assert(bfs_search(network, bfs_utils, &edge_has_residual_capacity_to));
	assert(trace->sink_edges.len == 0);
	assert(edge_other(trace->edge_to[7], 7) == 6);
	assert(edge_other(trace->edge_to[6], 6) == 3);
	assert(edge_other(trace->edge_to[3], 3) == 2);
	assert(edge_other(trace->edge_to[2], 2) == 5);
	assert(edge_other(trace->edge_to[5], 5) == 4);
	assert(edge_other(trace->edge_to[4], 4) == 1);
	assert(edge_other(trace->edge_to[1], 1) == 0);
}

static void	second_augment(t_flow_network *network, t_trace trace)
{
	assert(edge_augment_flow_to(trace.edge_to[7], 7, network));
	assert(edge_augment_flow_to(trace.edge_to[6], 6, network));
	assert(edge_augment_flow_to(trace.edge_to[3], 3, network));
	assert(edge_augment_flow_to(trace.edge_to[2], 2, network));
	assert(edge_augment_flow_to(trace.edge_to[5], 5, network));
	assert(edge_augment_flow_to(trace.edge_to[4], 4, network));
	assert(edge_augment_flow_to(trace.edge_to[1], 1, network));
}

static void	final_search(t_flow_network *network, t_bfs_utils *bfs_utils)
{
	t_trace	*trace;

	trace = &bfs_utils->trace;
	assert(bfs_search(network, bfs_utils, &edge_has_flow_to));
	assert(trace->sink_edges.len == 2);
	assert(edge_other(edge_list_get(&trace->sink_edges, 0), 7) == 5);
	assert(edge_other(trace->edge_to[5], 5) == 4);
	assert(edge_other(trace->edge_to[4], 4) == 1);
	assert(edge_other(trace->edge_to[1], 1) == 0);
	assert(edge_other(edge_list_get(&trace->sink_edges, 1), 7) == 6);
	assert(edge_other(trace->edge_to[6], 6) == 3);
	assert(edge_other(trace->edge_to[3], 3) == 2);
	assert(edge_other(trace->edge_to[2], 2) == 0);
}

void	test_bfs_search(void)
{
	t_flow_network	network;
	t_bfs_utils		bfs_utils;

	ft_printf("Testing bfs_search for path augmentation:\n");

	ft_printf("First search (1 path): ");
	init_dummy_network(&network);
	assert(bfs_init(&bfs_utils, &network, FALSE));
	first_search(&network, &bfs_utils);
	ft_printf("OK\n");

	ft_printf("Second search (2 paths): ");
	first_augment(&network, bfs_utils.trace);
	second_search(&network, &bfs_utils);
	ft_printf("OK\n");

	ft_printf("Searching for final paths: ");
	second_augment(&network, bfs_utils.trace);
	assert(bfs_search(&network, &bfs_utils, &edge_has_residual_capacity_to) == 0);
	bfs_utils.saturate_trace = 1;
	final_search(&network, &bfs_utils);
	ft_printf("OK\n");
	network_free(&network);
	bfs_free(&bfs_utils);
}
