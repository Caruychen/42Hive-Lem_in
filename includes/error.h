/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:35:19 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/22 17:18:18 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MSG_ERROR_INV_FILE "File did not contain ant number, rooms or links."
# define MSG_ERROR_INV_LINE "File contained an invalid line."
# define MSG_ERROR_GNL "Could not get next line."
# define MSG_ERROR_CHAR_ALIAS "Invalid character in room alias."
# define MSG_ERROR_MALLOC_VLINK "Could not allocate memory in is_valid_link."
# define MSG_ERROR_MOD "Invalid modification."
# define MSG_ERR_NETWORK_INIT "Could not initialize flow network."
# define MSG_ERR_HASH_INIT "Could not initialize hashmap."
# define MSG_ERR_HASH_GET "Could not get entry from hashmap."

int	error(char *msg);

#endif
