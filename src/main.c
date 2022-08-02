/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:44 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 17:36:44 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "printer.h"

int	main(void)
{
	t_flow_network	network;
	t_pathset		pathset;

	if (network_init(&network) == ERROR)
		return (error(MSG_ERR_NETWORK_INIT));
	if (parse_input(&network) == ERROR)
		return (network_free(&network), ERROR);
	if (solve(&network, &pathset) == ERROR)
		return (network_free(&network), ERROR);
	if (print_solution(&pathset) == ERROR)
	{
		network_free(&network);
		return (pathset_free(&pathset), ERROR);
	}
	network_free(&network);
	pathset_free(&pathset);
	return (0);
}
