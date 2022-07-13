/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:01:04 by carlnysten        #+#    #+#             */
/*   Updated: 2022/07/13 10:38:46 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	queue_has_next(t_queue *queue)
{
	if (queue->head == queue->tail)
		return (FALSE);
	return (TRUE);
}

int	queue_push(t_queue *queue, void *src)
{
	if (vec_push(&queue->vec, src) == ERROR)
		return (ERROR);
	queue->head++;
	return (OK);
}

void	*queue_pop(t_queue *queue)
{
	void	*elem;

	elem = vec_get(&queue->vec, queue->tail);
	if (!elem)
		return (NULL);
	queue->tail++;
	return (elem);
}

int	queue_init(t_queue *queue, size_t elem_size)
{
	queue->head = 0;
	queue->tail = 0;
	if (vec_new(&queue->vec, 1, elem_size) == ERROR)
		return (ERROR);
	return (OK);
}

void	queue_free(t_queue *queue)
{
	vec_free(&queue->vec);
	queue->head = 0;
	queue->tail = 0;
}
