/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:31:15 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 23:18:26 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

void	ft_putstr(char const *s)
{
	size_t	length;

	length = ft_strlen(s);
	write(1, s, length);
}
