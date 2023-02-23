/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:08:19 by oburato           #+#    #+#             */
/*   Updated: 2023/02/22 22:28:59 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ht_insert(t_ht *table, char *key, char *value)
{
	t_hi *item = ft_create_item(key, value);
	int index = ft_hash_function(key);
	t_hi *current_item = table->items[index];
	if (current_item == NULL)
	{
		if (table->count == table->size)
		{
			printf("Insert Error: Hash Table is full\n");
			ft_free_item(item);
			return;
		}
		table->items[index] = item;
		table->count++;
	}
	else
	{
		if (strcmp(current_item->key, key) == 0)
			strcpy(table->items[index]->value, value);
		else
			handle_collision(table, index, item);
		return;
	}
}

char *ht_search(t_ht *table, char *key)
{
	int index = ft_hash_function(key);
	t_hi *item = table->items[index];
	t_linkedlist *head = table->overflow_buckets[index];
	if (item != NULL)
	{
		if (strcmp(item->key, key) == 0)
			return item->value;
		if (head == NULL)
			return NULL;
		item = head->item;
		head = head->next;
	}
	return NULL;
}

void ht_delete(t_ht *table, char *key)
{
	int index = ft_hash_function(key);
	t_hi *item = table->items[index];
	t_linkedlist *head = table->overflow_buckets[index];
	if (item == NULL)
		return;
	else
	{
		if (head == NULL && strcmp(item->key, key) == 0)
		{
			table->items[index] = NULL;
			ft_free_item(item);
			table->count--;
			return;
		}
		else if (head != NULL)
		{
			if (strcmp(item->key, key) == 0)
			{
				ft_free_item(item);
				t_linkedlist *node = head;
				head = head->next;
				node->next = NULL;
				table->items[index] = ft_create_item(node->item->key, node->item->value);
				free_linkedlist(node);
				table->overflow_buckets[index] = head;
				return;
			}
			t_linkedlist *curr = head;
			t_linkedlist *prev = NULL;
			while (curr)
			{
				if (strcmp(curr->item->key, key) == 0)
				{
					if (prev == NULL)
					{
						free_linkedlist(head);
						table->overflow_buckets[index] = NULL;
						return;
					}
					else
					{
						prev->next = curr->next;
						curr->next = NULL;
						free_linkedlist(curr);
						table->overflow_buckets[index] = head;
						return;
					}
				}
				curr = curr->next;
				prev = curr;
			}
		}
	}
}
