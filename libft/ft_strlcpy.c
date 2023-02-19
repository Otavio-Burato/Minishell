/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:20:01 by oburato           #+#    #+#             */
/*   Updated: 2022/04/10 20:14:19 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	index;

	index = 0;
	len = ft_strlen(src);
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
