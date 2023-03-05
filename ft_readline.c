/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:53 by oburato           #+#    #+#             */
/*   Updated: 2023/03/05 12:06:40 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_sanitize_line(char *line)
{
	char	*clear_line;

	clear_line = ft_spacetrim(ft_strtrim(line, " "));
	free(line);
	return (clear_line);
}

void	ft_execute_the_line(char *line, char **env)
{
	char	**commands;
	int		index;

	index = 0;
	commands = ft_split(line, '|');
	free(line);
	while (commands[index])
	{
		g_data.pid = fork();
		ft_load_signal();
		if (g_data.pid == 0)
		{
			g_data.signal = exec_argv(commands[index], env);
			if (g_data.signal != 0)
			{
				ft_free_array(commands);
				exit(g_data.signal);
			}
		}
		else
			waitpid(g_data.pid, &g_data.signal, 0);
		index++;
	}
	ft_free_array(commands);
}

void	ft_read_line(char **env)
{
	char	*line;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	g_data.pwd_prompt = ft_strjoin(cwd, "$: ");
	free(cwd);
	line = readline(g_data.pwd_prompt);
	free(g_data.pwd_prompt);
	if (!line)
		exit(EOF); // TODO: chama a ft_exit
	if (line == NULL)
		return ;
	if (line && *line)
		add_history(line);
	line = ft_sanitize_line(line);
	ft_execute_the_line(line, env);
}
