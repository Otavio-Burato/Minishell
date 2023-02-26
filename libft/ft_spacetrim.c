/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:20:45 by oburato           #+#    #+#             */
/*   Updated: 2023/02/26 20:02:33 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spacetrim(char *string)
{
	int	index;
	int	aux;
	int	len;

	len = ft_strlen(string);
	index = 0;
	while (index < len)
	{
		if (ft_strchr("\"\'", string[index]))
			while (!ft_strchr("\"\'", string[index + 1]) && string[index + 1])
				index++;
		if (string[index] == ' ' && string[index + 1] == ' ')
		{
			aux = index;
			while (aux < (len - 1))
			{
				string[aux] = string[aux + 1];
				aux++;
			}
			string[aux] = '\0';
			len--;
			index--;
		}
		index++;
	}
	return (string);
}
