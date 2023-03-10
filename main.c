/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:23 by oburato           #+#    #+#             */
/*   Updated: 2023/03/10 00:10:19 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_data;

void	ft_clear_envs(void *content)
{
	t_envs	*map;

	map = (t_envs *)content;
	ft_free(map->key);
	ft_free(map->value);
	free(map);
}

t_envs	*ft_clonekeys(char **keys)
{
	t_envs	*map;

	map = malloc(sizeof(t_envs));
	map->key = ft_strdup(keys[0]);
	if (keys[1] != 0)
		map->value = keys[1];
	else
		map->value = ft_strdup("");
	ft_free_array(keys);
	return (map);
}

void	ft_load_args(char *envp[])
{
	int		index;
	t_envs	*map;

	map = malloc(sizeof(t_envs));
	map->key = "$?";
	map->value = "0";
	index = 0;
	g_data.list = ft_lstnew(map);
	while (envp[index] != NULL)
	{
		map = ft_clonekeys(ft_split(envp[index], '='));
		ft_lstlast(g_data.list)->next = ft_lstnew(map);
		index++;
	}
	ft_lstclear(&g_data.list, ft_clear_envs);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc > 1)
		exit(2);
	g_data.argv = argv;
	g_data.envp = envp;
	ft_load_args(envp);
	ft_load_signal();
	g_data.signal = 0;
	while (1)
	{
		ft_read_line(envp);
	}
	return (g_data.signal);
}
