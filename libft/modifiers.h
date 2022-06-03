/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:25:19 by cchen             #+#    #+#             */
/*   Updated: 2022/03/15 15:29:55 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_H
# define MODIFIERS_H

# define LEN_FLAG_INDEX_MAX 2

typedef enum e_length
{
	null,
	L,
	h,
	l,
	ll,
	hh,
}	t_length;

char	*mod_char(t_specs *specs);
char	*mod_short(t_specs *specs);
char	*mod_int(t_specs *specs);
char	*mod_long(t_specs *specs);

typedef char				*(*t_modifier)(t_specs *);

static const t_modifier		g_modifier[6] = {
	mod_int,
	mod_long,
	mod_short,
	mod_long,
	mod_long,
	mod_char
};

char	*mod_sign(t_specs specs);
int		mod_doubles(t_vec *result, t_vec *vec, t_specs specs);

#endif
