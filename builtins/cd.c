/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:58:05 by msander           #+#    #+#             */
/*   Updated: 2023/03/02 19:02:10 by oburato          ###   ########.fr       */
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
	printf("\n\n arg[1]: |%s|", args_splited[1]);
	printf("\n\n path: |%s|", path);
	path = ft_strtrim(path, " ");
	result = chdir(path);
	ft_free_array(args_splited);
	printf("chdir: %d\n\n", result);
	if (result == 0)
		return ;
	exit(-1);
}
