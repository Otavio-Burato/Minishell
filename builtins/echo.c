/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:25:12 by msander           #+#    #+#             */
/*   Updated: 2023/02/26 22:00:04 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char *cmd)
{
	int		i;
	char	**cmd_arg;

	cmd_arg = ft_split_ignore(cmd, ' ', '"');
	i = 1;
	if (ft_strncmp(cmd_arg[i], "-n", 2) == 0)
		i++;
	while (cmd_arg[i])
	{
		printf("%s", cmd_arg[i]);
		if(cmd_arg[i] +1 != 0)
			printf(" ");
		i++;
	}
	if (ft_strncmp(cmd_arg[1], "-n", 2) != 0)
		printf("\n");
	ft_free_array(cmd_arg);
}
