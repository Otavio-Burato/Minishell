/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:30:11 by oburato           #+#    #+#             */
/*   Updated: 2023/02/22 22:21:38 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned long	ft_hash_function(char *str)
{
	unsigned long	hash;
	int				index;

	hash = 0;
	index = 0;
	while (str[index])
		hash += str[index++];
	return (hash % CAPACITY);
}

t_hi	*ft_create_item(char *key, char *value)
{
	t_hi	*item;

	item = (t_hi *) malloc(sizeof(t_hi));
	item->key = (char *) malloc(ft_strlen(key) + 1);
	item->value = (char *) malloc(ft_strlen(value) + 1);
	ft_strlcpy(item->key, key, ft_strlen(item->key));
	ft_strlcpy(item->value, value, ft_strlen(item->value));
	return (item);
}

t_ht	*ft_create_table(int size)
{
	int				index;
	t_ht	*table;

	index = 0;
	table = (t_ht *) malloc(sizeof(t_ht));
	table->size = size;
	table->count = 0;
	table->items = (t_hi **) ft_calloc(table->size,
			sizeof(t_hi *));
	while (index < table->size)
	{
		table->items[index] = NULL;
		index++;
	}
	return (table);
}

void print_table(t_ht* table)
{
	printf("\nHash Table\n-------------------\n");

	for (int i = 0; i < table->size; i++)
	{
		if (table->items[i])
		{
			printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i] -> key, table->items[i]->value);
		}
	}

	printf("-------------------\n\n");
}
