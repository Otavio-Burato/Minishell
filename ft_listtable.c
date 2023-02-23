/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:02:46 by oburato           #+#    #+#             */
/*   Updated: 2023/02/22 22:07:46 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_linkedlist *allocate_list()
{
	t_linkedlist *list = (t_linkedlist *)malloc(sizeof(t_linkedlist));
	return list;
}

t_linkedlist *linkedlist_insert(t_linkedlist *list, t_hi *item)
{
	if (!list)
	{
		t_linkedlist *head = allocate_list();
		head->item = item;
		head->next = NULL;
		list = head;
		return list;
	}
	else if (list->next == NULL)
	{
		t_linkedlist *node = allocate_list();
		node->item = item;
		node->next = NULL;
		list->next = node;
		return list;
	}

	t_linkedlist *temp = list;

	while (temp->next->next)
	{
		temp = temp->next;
	}

	t_linkedlist *node = allocate_list();
	node->item = item;
	node->next = NULL;
	temp->next = node;
	return (list);
}

t_hi *linkedlist_remove(t_linkedlist *list)
{
	if (!list)
		return NULL;
	if (!list->next)
		return NULL;
	t_linkedlist *node = list->next;
	t_linkedlist *temp = list;
	temp->next = NULL;
	list = node;
	t_hi *it = NULL;
	memcpy(temp->item, it, sizeof(t_hi));
	free(temp->item->key);
	free(temp->item->value);
	free(temp->item);
	free(temp);
	return (it);
}

t_linkedlist **create_overflow_buckets(t_ht *table)
{
	t_linkedlist **buckets = (t_linkedlist **)calloc(table->size, sizeof(t_linkedlist *));

	for (int i = 0; i < table->size; i++)
		buckets[i] = NULL;

	return buckets;
}

void handle_collision(t_ht *table, unsigned long index, t_hi *item)
{
	t_linkedlist *head = table->overflow_buckets[index];

	if (head == NULL)
	{
		head = allocate_list();
		head->item = item;
		table->overflow_buckets[index] = head;
		return;
	}
	else
	{
		table->overflow_buckets[index] = linkedlist_insert(head, item);
		return;
	}
}
