/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:19:45 by cchen             #+#    #+#             */
/*   Updated: 2022/03/10 12:19:13 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	conv_ptr(t_vec *result, t_specs *specs)
{
	specs->flags |= HASH;
	specs->length = l;
	return (conv_num(result, specs));
}
