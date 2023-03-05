/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:20:18 by oburato           #+#    #+#             */
/*   Updated: 2023/03/04 17:50:42 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_load_signal(void)
{
	signal(SIGINT, ft_handle_sigint);
	signal(SIGQUIT, ft_handle_sigint);
}

void	ft_handle_sigint(int signum)
{
	char	*cwd;

	if (signum == SIGINT)
	{
		printf("\n");
		cwd = getcwd(NULL, 0);
		g_data.pwd_prompt = ft_strjoin(cwd, "$: ");
		printf("%s", g_data.pwd_prompt);
		free(cwd);
	}
}
