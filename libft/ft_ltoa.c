/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:11:10 by cchen             #+#    #+#             */
/*   Updated: 2022/02/28 11:29:18 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <limits.h>
#include "ft_string.h"
#include "ft_stdlib.h"

static int	_internal_ultoa(uintmax_t value, char *tmp, int base)
{
	int	index;

	index = MAX_LL_STR_SIZE - 1;
	tmp[index--] = '\0';
	while (value > 0)
	{
		tmp[index--] = HEX_STR_L[value % base];
		value /= base;
	}
	if (index == MAX_LL_STR_SIZE - 2)
		tmp[index--] = '0';
	return (index);
}

char	*ft_ltoa(intmax_t value, int base)
{
	char	tmp[MAX_LL_STR_SIZE];
	char	*res;
	int		index;
	int		sign;

	if (base < 2 || base > 16)
		return (NULL);
	sign = 1 - ((value < 0) * 2);
	index = _internal_ultoa(sign * value, tmp, base);
	if (sign == -1 && base == 10)
		tmp[index--] = '-';
	res = (char *)malloc(MAX_LL_STR_SIZE - index + 1);
	if (!res)
		return (NULL);
	return (ft_memcpy(res, &tmp[index + 1], MAX_LL_STR_SIZE - index + 1));
}
