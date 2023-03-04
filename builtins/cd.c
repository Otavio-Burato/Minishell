/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander <msander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:58:05 by msander           #+#    #+#             */
/*   Updated: 2023/03/04 17:12:10 by msander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char *args)
{
	char		**args_splited;
	const char	*path;
	int			result;

	args_splited = ft_split(args, ' ');
	path = (const char *) args_splited[1];
	path = ft_strtrim(path, " ");
	result = chdir(path);
	ft_free_array(args_splited);
	if (result == 0)
		return ;
	exit(-1);
}
