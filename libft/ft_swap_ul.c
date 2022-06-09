/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:26:20 by cchen             #+#    #+#             */
/*   Updated: 2022/06/09 13:26:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_ul(unsigned long *a, unsigned long *b)
{
	unsigned long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
