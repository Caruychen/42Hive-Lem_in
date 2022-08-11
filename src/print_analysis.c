/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:59:23 by cchen             #+#    #+#             */
/*   Updated: 2022/08/11 16:13:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_textful(t_pathset pathset)
{
	size_t	path_id;
	t_path	path;

	ft_printf("=============================================================\n");
	ft_printf("                        PATH ANALYSIS                        \n");
	ft_printf("=============================================================");
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
			ft_printf("%s", path_get(&path, --path.height)->alias);
			if (path.height > 0)
				ft_putstr(" -> ");
		}
		ft_putendl("");
		++path_id;
	}
	ft_putendl("");
}

void	print_chart(t_pathset pathset)
{
	size_t	path_id;
	t_path	path;

	ft_putendl("============================================================\n");
	ft_printf("Travel chart:\n\n");
	path_id = 0;
	while (path_id < pathset.paths.len)
	{
		path = *pathset_get(&pathset, path_id);
		ft_printf("%ld:%2s", path_id, "");
		while (path.height-- > 0)
			ft_putchar('#');
		while (path.ants-- > 0)
			ft_putchar('~');
		ft_putendl("");
		++path_id;
	}
	ft_putendl("============================================================\n");
}

void	print_analysis(t_pathset pathset)
{
	print_textful(pathset);
	print_chart(pathset);
}
