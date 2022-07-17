/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:17:07 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/17 14:04:06 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

typedef struct s_info
{
	unsigned char	verbose;
	unsigned char	quiet;
	char			*source;
	char			*sink;
	long			n_ants;
}	t_info;

#endif
