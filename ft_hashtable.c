/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:30:11 by oburato           #+#    #+#             */
/*   Updated: 2023/02/20 22:21:21 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// struct hash table
typedef struct s_hash_item
{
	char	*key;
	char	*value;
}	t_hash_item;

typedef struct s_hash_table
{
	t_hash_item	**items;
	int			size;
	int			count;
}	t_hash_table;

#define CAPACITY 50000 // Size of the HashTable.

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

t_hash_item	*create_item(char *key, char *value)
{
	t_hash_item	*item;

	item = (t_hash_item *) malloc(sizeof(t_hash_item));
	item->key = (char *) malloc(ft_strlen(key) + 1);
	item->value = (char *) malloc(ft_strlen(value) + 1);
	ft_strlcpy(item->key, key);
	ft_strlcpy(item->value, value);
	return (item);
}

t_hash_table	*create_table(int size)
{
	int				index;
	t_hash_table	*table;

	index = 0;
	table = (t_hash_table *) malloc(sizeof(t_hash_table));
	table->size = size;
	table->count = 0;
	table->items = (t_hash_item **) ft_calloc(table->size,
			sizeof(t_hash_item *));
	while (index < table->size)
	{
		table->items[index] = NULL;
		index++;
	}
	return (table);
}
