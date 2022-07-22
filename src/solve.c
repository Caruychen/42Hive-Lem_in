/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:57:21 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/22 11:37:07 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "parser.h"

int	solve(t_vec *network, t_info *info)
{
	t_vec	paths;

	if (vec_new(&paths, 1, sizeof (t_vec)) == ERROR)
		return (ERROR);
	if (edmonds_karp(network, info) == ERROR)
		return (vec_free(&paths), ERROR);
	if (get_paths(network, info, &paths) == ERROR)
		return (vec_free(&paths), ERROR);
	if (send_ants(info, &paths) == ERROR)
		return (vec_free(&paths), ERROR);
	return (OK);
}
