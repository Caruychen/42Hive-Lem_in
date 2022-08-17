/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:59:23 by cchen             #+#    #+#             */
/*   Updated: 2022/08/17 14:38:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_header(void)
{
	ft_putendl("=============================================================");
	ft_putendl("                        PATH ANALYSIS                        ");
	ft_putendl("=============================================================");
}

static void	print_textful(t_pathset pathset)
{
	size_t		path_id;
	t_path		path;
	t_flow_node	node;

	print_header();
	ft_printf("\nTotal paths: %ld\nTotal ants: %ld\n", pathset.paths.len,
		pathset.ants);
	path_id = 0;
	while (path_id < pathset.paths.len)
	{
		path = *pathset_get(&pathset, path_id);
		ft_printf("\n    Path %ld: (Rooms: %ld, Ants: %ld)\n\t",
			path_id, path.height, path.ants);
		while (path.height > 0)
		{
			node = *path_get(&path, --path.height);
			ft_putstr(node.alias);
			if (path.height > 0)
				ft_putstr(" -> ");
		}
		ft_putchar('\n');
		++path_id;
	}
	ft_putendl("");
}

void	print_chart(t_pathset pathset)
{
	size_t	path_id;
	t_path	path;

	ft_putendl("============================================================\n");
	ft_putendl("Travel chart: (Total steps is the number of chars - 1)");
	ft_putendl("Rooms: #, Ants: ~\n");
	path_id = 0;
	while (path_id < pathset.paths.len)
	{
		path = *pathset_get(&pathset, path_id);
		ft_printf("%ld:\t", path_id, "");
		while (path.height-- > 0)
			ft_putchar('#');
		while (path.ants-- > 0)
			ft_putchar('~');
		ft_putendl("");
		++path_id;
	}
	ft_printf("\nSolved with %i steps.\n", (int) pathset.steps);
	ft_putendl("============================================================\n");
}

void	print_analysis(t_pathset pathset)
{
	print_textful(pathset);
	print_chart(pathset);
}
