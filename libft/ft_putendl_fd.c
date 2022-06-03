/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:48:43 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 23:12:57 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	length;
	char	new_line;

	new_line = '\n';
	length = ft_strlen(s);
	write(fd, s, length);
	write(fd, &new_line, 1);
}
