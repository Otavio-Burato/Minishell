/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander <msander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:05:13 by msander           #+#    #+#             */
/*   Updated: 2023/03/13 19:01:58 by msander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	char	path[FILENAME_MAX];

	if (getcwd(path, sizeof(path)))
		printf("%s\n", path);
	else
		perror("getcwd() error");
}
