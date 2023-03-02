/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:20:18 by oburato           #+#    #+#             */
/*   Updated: 2023/02/19 14:00:14 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_load_signal(void)
{
	sigset_t	mask;
	t_sigaction	sigint;

	sigemptyset(&mask);
	sigint.sa_flags = SA_RESTART;
	sigint.sa_mask = mask;
	sigint.sa_handler = &ft_handle_sigint;
	sigaction(SIGINT, &sigint, NULL);
}

void	ft_handle_sigint(int signal)
{
	printf("^C\n");
	ft_destruct_global_variable();
	exit(signal);
}
