/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:18:35 by cchen             #+#    #+#             */
/*   Updated: 2022/07/20 14:28:17 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <string.h>

# define HASH_OK 1
# define HASH_ERR -1
# define MSG_ERR_HASH_OVER "Error: Hash value out of bounds."
# define MSG_ERR_HASHMAP_FULL "Error: Hashmap full, couldn't add element."
# define MSG_ERR_NO_KEY "Error: Key not found in Hashmap."
# define MSG_ERR_HASHMAP_EMTPY "Error: Hashmap empty."
# define DJB2_SEED 5281
# define HASH_NEW_CAPACITY 2

typedef struct s_entry
{
	char	*key;
	int		value;
}	t_entry;

t_entry			hashmap_create_entry(char *key, int value);
int				hashmap_free_entry(t_entry *entry);

typedef struct s_hashmap
{
	t_entry	*entries;
	size_t	capacity;
	size_t	len;
}	t_hashmap;

unsigned long	hashmap_hasher(t_hashmap *dst, char *str);
int				hashmap_new(t_hashmap *dst);
int				hashmap_new_with_capacity(t_hashmap *dst, size_t capacity);
size_t			hashmap_find_slot(t_hashmap *src, char *key);
t_entry			*hashmap_entry(t_hashmap *src, char *key);
int				*hashmap_get(t_hashmap *src, char *key);
t_entry			*hashmap_insert(t_hashmap *dst, char	*key, int value);
t_entry			*hashmap_try_insert(t_hashmap *dst, char *key, int value);
int				hashmap_remove(t_hashmap *dst, char *key);
void			hashmap_free(t_hashmap *src);

#endif
