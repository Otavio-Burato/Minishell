/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaner- <msander-@student.42sp.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:38:50 by msaner-           #+#    #+#             */
/*   Updated: 2022/11/21 23:18:00 by msaner-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**find_paths(char **env)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}

char	*find_path(char *cmd, char **env)
{
	char	*full_path;
	char	**paths;
	char	*aux;
	int		i;

	i = 0;
	paths = find_paths(env);
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(full_path, F_OK) == 0)
		{
			ft_free_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free_array(paths);
	return (0);
}
