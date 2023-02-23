/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:23 by oburato           #+#    #+#             */
/*   Updated: 2023/02/22 22:40:56 by oburato          ###   ########.fr       */
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

	// t_ht *ht = ft_create_table(CAPACITY);
	// ht_insert(ht, (char *)"1", (char *)"First address");
	// print_table(ht);
	// ht_insert(ht, (char *)"2", (char *)"Second address");
	// print_table(ht);
	// ht_insert(ht, (char *)"Hel", (char *)"Third address");
	// print_table(ht);
	// ht_insert(ht, (char *)"Cau", (char *)"Fourth address");
	// print_table(ht);
	// ht_delete(ht, (char *)"1");
	// ht_delete(ht, (char *)"Cau");
	// print_table(ht);
	// ft_free_table(ht);
	while (1)
	{
		ft_read_line(envp);
	}
	return (0);
}
