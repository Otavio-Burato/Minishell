/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:20:45 by oburato           #+#    #+#             */
/*   Updated: 2023/02/26 21:05:56 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip(char *string, int *index)
{
	char	ignore;

	if (ft_strchr("\"\'", string[*index]))
	{
		ignore = string[*index];
		while ((ignore != string[*index + 1]) && string[*index + 1])
			(*index)++;
		(*index)++;
	}
}

char	*ft_spacetrim(char *string)
{
	int		index;
	int		aux;
	int		len;

	len = ft_strlen(string);
	index = 0;
	while (index++ < len)
	{
		ft_skip(string, &index);
		if (string[index] == ' ' && string[index + 1] == ' ')
		{
			aux = index;
			while (aux++ < (len - 1))
				string[aux] = string[aux + 1];
			string[aux] = '\0';
			len--;
			index--;
		}
	}
	return (string);
}
