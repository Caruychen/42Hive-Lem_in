/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:07:53 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/20 11:10:57 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDMONDS_KARP_H
# define EDMONDS_KARP_H

# include "lem_in.h"

typedef struct s_edm_karp
{
	int			flow;
	long		source_id;
	long		sink_id;
	t_flow_node	*source;
	t_flow_node	*sink;
	t_vec		parent_array;
}	t_edm_karp;

#endif
