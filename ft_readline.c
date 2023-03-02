/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:53 by oburato           #+#    #+#             */
/*   Updated: 2023/03/02 19:01:57 by oburato          ###   ########.fr       */
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

void	execute_the_line(char *line, char **env)
{
	pid_t	pid;
	char	**commands;
	int		index;
	int		response;

	index = 0;
	commands = ft_split(line, '|');
	free(line);
	while (commands[index])
	{
		pid = fork();
		if (pid == 0)
		{
			response = exec_argv(commands[index], env);
			if (response != 0)
			{
				ft_free_array(commands);
				exit(response);
			}
		}
		else
			waitpid(pid, NULL, 0);
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
	if (line == NULL)
		return ;
	if (line && *line)
		add_history(line);
	line = ft_sanitize_line(line);
	execute_the_line(line, env);
}
