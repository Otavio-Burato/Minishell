/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander <msander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:25:12 by msander           #+#    #+#             */
/*   Updated: 2023/02/22 17:28:08 by msander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	echo(char *cmd)
{
	int		i;
	char	**cmd_arg;

	cmd_arg = ft_split(cmd, ' ');
	i = 1;
	if (ft_strncmp(cmd_arg[i], "-n", 2) == 0)
		i++;
	while (cmd_arg[i])
	{
		printf("%s", cmd_arg[i]);
		i++;
	}
	if (ft_strncmp(cmd_arg[1], "-n", 2) != 0)
		printf("\n");
}