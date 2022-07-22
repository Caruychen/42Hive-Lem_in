/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:13:07 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/22 11:48:56 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	error(char *msg)
{
	ft_putstr_fd(__FILE__, 2);
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(__LINE__, 2);
	ft_putstr_fd(" -> ", 2);
	ft_putendl_fd(msg, 2);
	return (ERROR);
}
