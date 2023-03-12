/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stracpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:12:16 by oburato           #+#    #+#             */
/*   Updated: 2023/03/12 13:20:42 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_stracpy(char **dst, char **src, size_t size)
{
	size_t	len;
	size_t	index;

	index = 0;
	len = ft_stralen(src);
	if (size == 0)
		return (len);
	while (src[index] && (index < size - 1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (len);
}
