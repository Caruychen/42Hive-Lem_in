/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:44 by cchen             #+#    #+#             */
/*   Updated: 2022/06/27 22:01:34 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_vec	network;
	t_info	info;

	if (network_init(&network) == ERROR)
		return (error(MSG_ERR_NETWORK_INIT));
	if (parse_input(&network, &info) == ERROR)
		return (network_free(&network), ERROR);
	network_free(&network);
	return (0);
}
