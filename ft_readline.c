/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:53 by oburato           #+#    #+#             */
/*   Updated: 2023/02/19 10:31:51 by oburato          ###   ########.fr       */
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
	free(cwd);
	line = readline(g_data.pwd_prompt);
	free(g_data.pwd_prompt);
	if (line == NULL)
		return ;
	if (line && *line)
		add_history(line);
	ft_sanitize_line(line);
	free(g_data.cmd);
	g_data.cmd = line;
}
