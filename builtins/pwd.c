/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander <msander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:05:13 by msander           #+#    #+#             */
/*   Updated: 2023/03/04 17:11:18 by msander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(char **env)
{
	char	*path;

	path = find_in_env(env, "PWD");
	path = path + 4;
	printf("%s\n", path);
}
