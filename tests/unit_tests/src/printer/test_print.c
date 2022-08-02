/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:24:15 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/02 10:09:42 by carlnysten       ###   ########.fr       */
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
#include "lem_in.h"
#include "unit_test.h"
#include "vec.h"

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

static void	init_dummy_pathset(t_pathset *pathset)
{
	t_path	path_a;
	t_path	path_b;
	size_t	nodes_a[] = {0, 1, 4, 5, 7};
	size_t	nodes_b[] = {0, 2, 3, 6, 7};

	path_a = (t_path){.ants = 3};
	path_b = (t_path){.ants = 2};
	assert(vec_from(&path_a.nodes, nodes_a, 5, sizeof (size_t)));
	assert(vec_from(&path_b.nodes, nodes_b, 5, sizeof (size_t)));
	*pathset = (t_pathset){.ants = 5, .steps = 6};
	assert(vec_new(&pathset->paths, 2, sizeof (t_path)) != ERROR);
	assert(vec_push(&pathset->paths, &path_a) != ERROR);
	assert(vec_push(&pathset->paths, &path_b) != ERROR);
}

void	test_print(void)
{
	t_flow_network	network;
	t_pathset		pathset;

	init_dummy_pathset(&pathset);
	init_dummy_network(&network);
	assert(print(&network, &pathset) == OK);
	network_free(&network);
	pathset_free(&pathset);
}
