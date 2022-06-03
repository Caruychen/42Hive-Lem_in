/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:40:35 by cchen             #+#    #+#             */
/*   Updated: 2022/03/15 15:41:22 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdint.h>

typedef union s_dcast
{
	double		d;
	uint64_t	u;
}			t_dcast;

int			ft_imin(const int n1, const int n2);
int			ft_imax(const int n1, const int n2);
int			ft_sqrt(int nb);
double		ft_fmod(double x, double y);
long double	ft_ldmod(long double x, long double y);
long long	ft_pow(long long x, long long y);

#endif
