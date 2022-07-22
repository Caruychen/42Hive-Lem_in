/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:58:42 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/22 11:36:52 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

int	solve(t_vec *network, t_info *info);
int	send_ants(t_info *info, t_vec *paths);
int	edmonds_karp(t_vec *network, t_info *info);
int	get_paths(t_vec *network, t_info *info, t_vec *paths);

#endif
