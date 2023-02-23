/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:39:52 by msander           #+#    #+#             */
/*   Updated: 2023/02/22 22:20:01 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_array(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
	{
		ft_free(ptr[len]);
		len++;
	}
	ft_free(ptr);
}

void ft_free_item(t_hi* item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void ft_free_table(t_ht* table)
{
	for (int i = 0; i < table->size; i++)
	{
		t_hi* item = table->items[i];

		if (item != NULL)
		ft_free_item(item);
	}

	free(table->items);
	free(table);
}

void free_linkedlist(t_linkedlist *list)
{
	t_linkedlist *temp = list;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->item->key);
		free(temp->item->value);
		free(temp->item);
		free(temp);
	}
}

void free_overflow_buckets(t_ht *table)
{
	t_linkedlist **buckets = table->overflow_buckets;

	for (int i = 0; i < table->size; i++)
		free_linkedlist(buckets[i]);
	free(buckets);
}
