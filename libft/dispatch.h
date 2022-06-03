/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:15:21 by cchen             #+#    #+#             */
/*   Updated: 2022/03/10 10:43:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

# include <stdarg.h>
# include "vec.h"

typedef struct s_specs
{
	va_list				ap;
	long				value;
	char				spec;
	int					sign;
	unsigned int		length : 3;
	unsigned int		is_signed : 1;
	unsigned int		flags: 5;
	unsigned int		precision;
	unsigned int		precision_on : 1;
	unsigned int		width;
	char				pad_char;
}	t_specs;

int	append_char(t_vec *result, t_specs *specs, char c);
int	conv_char(t_vec *result, t_specs *specs);
int	conv_string(t_vec *result, t_specs *specs);
int	conv_num(t_vec *result, t_specs *specs);
int	conv_ptr(t_vec *result, t_specs *specs);
int	conv_dbl(t_vec *result, t_specs *specs);

typedef int					(*t_dispatcher)(t_vec *, t_specs *);

static const t_dispatcher	g_dispatcher[26] = {
	NULL,
	NULL,
	conv_char,
	conv_num,
	NULL,
	conv_dbl,
	NULL,
	NULL,
	conv_num,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	conv_num,
	conv_ptr,
	NULL,
	NULL,
	conv_string,
	NULL,
	conv_num,
	NULL,
	NULL,
	conv_num,
	NULL,
	NULL,
};

#endif
