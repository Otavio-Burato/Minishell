/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:20:18 by oburato           #+#    #+#             */
/*   Updated: 2023/03/03 18:51:30 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_load_signal(void)
{
	sigset_t	mask;
	t_sigaction	act;

	sigfillset(&mask);
	act.sa_mask = mask;
	act.sa_flags = SA_RESTART;
	act.sa_handler = &ft_handle_sigint;
	sigaction(SIGINT, &act, NULL);
}

void	ft_handle_sigint(int signal)
{
	if (g_data.pid)
	{
		kill(g_data.pid, signal);
		printf("\n");
	}
	else
		printf("\n");
}
