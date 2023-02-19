/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:53 by oburato           #+#    #+#             */
/*   Updated: 2023/02/18 22:06:01 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_sanitize_line(char *line)
{
	if (!line)
		return (0);
	return (1);
}

void	ft_read_line(void)
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
	free(g_data.cmd);
	ft_sanitize_line(line);
	g_data.cmd = line;
}
