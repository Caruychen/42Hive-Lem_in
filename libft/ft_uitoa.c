/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:05:46 by cchen             #+#    #+#             */
/*   Updated: 2022/08/11 14:22:41 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_stdlib.h"

char	*ft_uitoa(unsigned int value, int base, int uppercase)
{
	uintmax_t	new_value;

	if (base < 2 || base > 16)
		return (NULL);
	new_value = value;
	return (ft_ultoa(new_value, base, uppercase));
}
