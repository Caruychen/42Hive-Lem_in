/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:57:21 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/17 17:22:38 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	solve(t_vec *network, t_info *info)
{
	t_vec	paths;

	if (vec_new(&paths, 1, sizeof (t_vec)) == ERROR)
		return (ERROR);
	if (edmonds_karp(network, info, &paths) == ERROR)
		return (ERROR);
	if (send_ants(info, &paths) == ERROR)
		return (ERROR);
	return (OK);
}
