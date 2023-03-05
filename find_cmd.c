/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:38:50 by msaner-           #+#    #+#             */
/*   Updated: 2023/03/05 11:58:10 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_in_env(char **env, char *target)
{
	int		i;

	i = 0;
	while (ft_strnstr(env[i], target, ft_strlen(target)) == 0)
		i++;
	return (env[i]);
}

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

int	ft_execute(char *argv, char **env)
{
	char	*path;
	char	**cmd_arg;

	cmd_arg = ft_split_ignore(argv, ' ', '\'');
	path = find_path(cmd_arg[0], env);
	if (!path)
	{
		ft_free_array(cmd_arg);
		return (127);
	}
	g_data.signal = execve(path, cmd_arg, env);
	return (0);
}

int	exec_argv(char *argv, char **env)
{
	if (ft_strncmp(argv, "echo", 4) == 0)
		ft_echo(argv);
	else if (ft_strncmp(argv, "cd", 2) == 0)
		ft_cd(argv);
	else if (ft_strncmp(argv, "pwd", 3) == 0)
		ft_pwd(env);
	else
		return (ft_execute(argv, env));
	return (0);
}
