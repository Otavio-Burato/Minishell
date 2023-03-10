/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:12:41 by oburato           #+#    #+#             */
/*   Updated: 2023/03/10 00:03:11 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	db_printlst(void)
{
	t_list	*envp = g_data.list;

	while (envp->next)
	{
		db_printkey((t_envs *)envp->content);
		envp = envp->next;
	}
	db_printkey((t_envs *)envp->content);
}

void	db_printkey(t_envs	*map)
{
	printf("{%s}=>{%s}\n", map->key, map->value);
}

void	db_printenvp(char **envp)
{
	char	**env;
	int		index;

	env = envp;
	index = 0;
	while (*env != 0)
	{
		printf("%s\n", *env);
		env++;
		index++;
	}
	printf("\ntotal de: %d\n\n", index);
}
