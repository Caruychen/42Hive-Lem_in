/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:57:21 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/07 11:11:15 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	solve(t_vec *network, t_info *info)
{
	t_vec	paths;

	if (edmonds_karp(network, info, &paths) == ERROR)
		return (ERROR);
	if (assign_ants_to_paths(info, &paths) == ERROR)
		return (ERROR);
	return (OK);
}
