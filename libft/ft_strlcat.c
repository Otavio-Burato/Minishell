/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:25:32 by oburato           #+#    #+#             */
/*   Updated: 2022/05/01 04:39:40 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	index;

	index = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dest || size == 0)
		return (size + len_src);
	while (src[index] && len_dest < size - 1)
	{
		dst[len_dest] = src[index];
		len_dest++;
		index++;
	}
	dst[len_dest] = '\0';
	return (len_src + (len_dest - index));
}
