/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:17:07 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/12 11:27:44 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

typedef struct s_info
{
	char	*source;
	char	*sink;
	long	n_ants;
	int		max_flow;
}	t_info;

#endif
