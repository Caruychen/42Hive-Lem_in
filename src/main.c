/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:44 by cchen             #+#    #+#             */
/*   Updated: 2022/07/17 14:08:31 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	handle_flags(int argc, char **argv, t_info *info)
{
	int	i;

	if (argc == 1)
		return (OK);
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[1], "-q"))
			info->quiet = 1;
		else if (ft_strcmp(argv[1], "-v"))
			info->verbose = 1;
		i++;
	}
	return (OK);
}

int	main(int argc, char **argv)
{
	t_vec	network;
	t_info	info;

	info = (t_info){0};
	if (handle_flags(argc, argv, &info) == ERROR)
		return (error(MSG_ERROR_INV_FLAGS));
	if (network_init(&network) == ERROR)
		return (error(MSG_ERR_NETWORK_INIT));
	if (parse_input(&network, &info) == ERROR)
		return (network_free(&network), ERROR);
	network_free(&network);
	return (0);
}
