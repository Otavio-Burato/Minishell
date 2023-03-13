/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander <msander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:20:18 by oburato           #+#    #+#             */
/*   Updated: 2023/03/13 19:10:42 by msander          ###   ########.fr       */
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
