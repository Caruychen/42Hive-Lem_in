/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:58:42 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/11 21:47:22 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

int	solve(t_vec *network, t_info *info);
int	send_ants(t_info *info, t_vec *paths);
int	edmonds_karp(t_vec *network, t_info *info, t_vec *paths);

#endif
