/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:23 by oburato           #+#    #+#             */
/*   Updated: 2023/03/05 12:06:21 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_data;

static void	ft_load_args(int argc, char *argv[], char *envp[])
{
	if (argc > 1)
		exit(2);
	g_data.argv = argv;
	g_data.envp = envp;
}

int	main(int argc, char *argv[], char *envp[])
{
	ft_load_args(argc, argv, envp);
	ft_load_signal();
	g_data.signal = 0;
	while (1)
	{
		ft_read_line(envp);
	}
	return (g_data.signal);
}
