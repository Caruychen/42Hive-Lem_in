/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:59:43 by cchen             #+#    #+#             */
/*   Updated: 2022/03/15 15:41:12 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static void	_normalise(uint64_t *u, int	*e)
{
	uint64_t	mantissa_tmp;

	if (!*e)
	{
		mantissa_tmp = *u << 12;
		while (mantissa_tmp >> 63 == 0)
		{
			e--;
			mantissa_tmp <<= 1;
		}
		*u <<= -(*e) + 1;
		return ;
	}
	*u &= -1ULL >> 12;
	*u |= 1ULL << 52;
}

static uint64_t	_get_diff(uint64_t *i, uint64_t *ux, uint64_t *uy)
{
	*i = *ux - *uy;
	if (*i >> 63 == 0)
	{
		if (*i == 0)
			return (0);
		*ux = *i;
	}
	return (*i);
}

static uint64_t	_x_mod_y(uint64_t *ux, uint64_t *uy, int *ex, int *ey)
{
	uint64_t	i;

	while (*ex > *ey)
	{
		if (!_get_diff(&i, ux, uy))
			return (0);
		*ux <<= 1;
		(*ex)--;
	}
	if (!_get_diff(&i, ux, uy))
		return (0);
	while (*ux >> 52 == 0)
	{
		*ux <<= 1;
		(*ex)--;
	}
	return (i);
}

static void	_scale_result(uint64_t *ux, int ex)
{
	if (ex > 0)
	{
		*ux -= 1ULL << 52;
		*ux |= (uint64_t) ex << 52;
	}
	else
		*ux >>= -ex + 1;
}

long double	ft_ldmod(long double x, long double y)
{
	t_dcast		ux;
	t_dcast		uy;
	int			ex;
	int			ey;

	ux.d = x;
	uy.d = y;
	ex = ux.u >> 52 & 0x7ff;
	ey = uy.u >> 52 & 0x7ff;
	if (ux.u << 1 <= uy.u << 1)
	{
		if (ux.u << 1 == uy.u << 1)
			return (0);
		return (x);
	}
	_normalise(&ux.u, &ex);
	_normalise(&uy.u, &ey);
	if (!_x_mod_y(&ux.u, &uy.u, &ex, &ey))
		return (0);
	_scale_result(&ux.u, ex);
	ux.u |= (uint64_t)(x < 0) << 63;
	return (ux.d);
}
