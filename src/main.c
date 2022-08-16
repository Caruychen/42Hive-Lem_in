/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:44 by cchen             #+#    #+#             */
/*   Updated: 2022/08/16 15:10:50 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_options		options;
	t_flow_network	network;
	t_pathset		pathset;
	t_vec			inputs;
	int				result;

	if (options_init(&options, argc, argv) == ERROR)
		return (ft_putendl(MSG_USAGE), OK);
	if (network_init(&network) == ERROR)
		return (error(MSG_ERR_NETWORK_INIT));
	if (parse_input(&network, &options, &inputs) == ERROR)
		return (network_free(&network), ERROR);
	if (solve(&network, &pathset) == ERROR)
		return (network_free(&network), ERROR);
	result = print_result(&pathset, &inputs, options);
	return (main_free(result, &network, &pathset));
}
