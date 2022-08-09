/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:35:19 by carlnysten        #+#    #+#             */
/*   Updated: 2022/08/09 15:37:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MSG_ERROR_INV_FILE "ERROR: File did not contain ant number, rooms or links."
# define MSG_ERROR_INV_LINE "ERROR: File contained an invalid line."
# define MSG_ERROR_INV_LINK "Error: File contained an invalid link input"
# define MSG_ERROR_GNL "ERROR: Could not get next line."
# define MSG_ERROR_CHAR_ALIAS "ERROR: Invalid character in room alias."
# define MSG_ERROR_MALLOC_VLINK "ERROR: Could not allocate memory in is_valid_link."
# define MSG_ERROR_MOD "ERROR: Invalid modification."
# define MSG_ERR_NETWORK_INIT "ERROR: Could not initialize flow network."
# define MSG_ERR_HASH_INIT "ERROR: Could not initialize hashmap."
# define MSG_ERR_HASH_GET "ERROR: Could not get entry from hashmap."

int	error(char *msg);
int	main_free(int res, t_flow_network *network, t_pathset *pathset);

#endif
