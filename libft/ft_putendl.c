/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:29 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 23:10:50 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

void	ft_putendl(char const *s)
{
	size_t	length;
	char	new_line;

	new_line = '\n';
	length = ft_strlen(s);
	write(1, s, length);
	write(1, &new_line, 1);
}
