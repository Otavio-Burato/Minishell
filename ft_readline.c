/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander <msander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:53 by oburato           #+#    #+#             */
/*   Updated: 2023/02/23 00:18:48 by msander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_sanitize_line(char *line)
{
	if (!line)
		return (0);
	return (1);
}

static void	execute_the_line(char *line, char **env)
{
	pid_t	pid;
	char	**commands;

	commands = ft_split(line, '|');

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
}

void	ft_read_line(char **env)
{
	char	*line;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	g_data.pwd_prompt = ft_strjoin(cwd, "$: ");
	line = readline(g_data.pwd_prompt);
	free(g_data.pwd_prompt);
	free(cwd);
	if (line == NULL)
		return ;
	if (line && *line)
		add_history(line);
	execute_the_line(line, env);
	free(g_data.cmd);
	ft_sanitize_line(line);
	g_data.cmd = line;
}
