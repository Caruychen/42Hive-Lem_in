/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:18:35 by cchen             #+#    #+#             */
/*   Updated: 2022/07/19 14:34:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# define HASH_OK 1
# define HASH_ERR -1
# define MSG_ERR_HASH_OVER "Error: Hash value out of bounds."
# define MSG_ERR_HASHMAP_FULL "Error: Hashmap full, couldn't add element."
# define DJB2_SEED 5281

typedef struct s_entry
{
	char	*key;
	int		value;
}	t_entry;

typedef struct s_hashmap
{
	t_entry	*entries;
	size_t	capacity;
	size_t	len;
}	t_hashmap;

unsigned long	hashmap_hasher(t_hashmap *dst, char *str);
int				hashmap_new(t_hashmap *dst);
int				hashmap_new_with_capacity(t_hashmap *dst, size_t capacity);
t_entry			*hashmap_entry(t_hashmap *src, char *key);
int				*hashmap_get(t_hashmap *src, char *key);
int				hashmap_insert(t_hashmap *dst, char	*key, int value);
int				hashmap_try_insert(t_hashmap *dst, char *key, int value);
int				hashmap_remove(t_hashmap *dst, char *key);
void			hashmap_free(t_hashmap *src);

#endif
