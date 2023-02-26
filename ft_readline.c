/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:53 by oburato           #+#    #+#             */
/*   Updated: 2023/02/26 20:09:15 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_sanitize_line(char *line)
{
	line = ft_strtrim(line, " ");
	line = ft_spacetrim(line);
	return (line);
}

void	execute_the_line(char *line, char **env)
{
	pid_t	pid;
	char	**commands;

	commands = ft_split(line, '|');
	free(line);
	while(*commands)
	{
		pid = fork();
		if(pid == 0)
			exec_argv(*commands, env);
		else
		{
			waitpid(pid, NULL, 0);
		}
		commands++;
	}
	ft_free_array(commands);
}

void	ft_read_line(char **env)
{
	char	*line;
	char	*cwd;
	printf("\nok:\t%s\n", *env);

	cwd = getcwd(NULL, 0);
	g_data.pwd_prompt = ft_strjoin(cwd, "$: ");
	line = readline(g_data.pwd_prompt);
	free(g_data.pwd_prompt);
	free(cwd);
	if (line == NULL)
		return ;
	if (line && *line)
		add_history(line);
	ft_sanitize_line(line);
	// execute_the_line(line, env);
	free(line);
}
