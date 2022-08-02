/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:44 by cchen             #+#    #+#             */
/*   Updated: 2022/08/02 13:56:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	network_free(&network);
	pathset_free(&pathset);
	//system("leaks lem-in");
	return (0);
}
