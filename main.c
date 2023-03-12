/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:23 by oburato           #+#    #+#             */
/*   Updated: 2023/03/12 14:09:21 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_data;

int	main(int argc, char *argv[], char *envp[])
{
	char	**envc;

	if (argc > 1)
		exit(2);
	g_data.argv = argv;
	envc = 0;
	envc = malloc(ft_stralen(envp));
	ft_stracpy(envc, envp, ft_stralen(envc));
	g_data.envp = envc;
	ft_load_signal();
	g_data.signal = 0;
	while (1)
		ft_read_line();
	return (ft_exit(g_data.signal));
}
