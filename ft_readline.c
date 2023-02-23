/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander <msander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:53 by oburato           #+#    #+#             */
/*   Updated: 2023/02/22 23:36:42 by msander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_sanitize_line(char *line)
{
	if (!line)
		return (0);
	return (1);
}

void	ft_read_line(char **env)
{
	char	*line;
	char	*cwd;
	pid_t	pid;

	cwd = getcwd(NULL, 0);
	g_data.pwd_prompt = ft_strjoin(cwd, "$: ");
	line = readline(g_data.pwd_prompt);
	free(g_data.pwd_prompt);
	free(cwd);
	if (line == NULL)
		return ;
	if (line && *line)
		add_history(line);
	pid = fork();
	if(pid == 0)
		exec_argv(line, env);
	else
	{
		waitpid(pid, NULL, 0);
	}
	free(g_data.cmd);
	ft_sanitize_line(line);
	g_data.cmd = line;
}
