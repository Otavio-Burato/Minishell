/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:18:51 by oburato           #+#    #+#             */
/*   Updated: 2022/04/24 18:22:57 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*ptr;
	unsigned char	unsigd_c;

	index = 0;
	unsigd_c = (unsigned char) c;
	ptr = (unsigned char *)s;
	if (!n)
		return (0);
	while (index < n)
	{
		if (((unsigned char *)s)[index] == unsigd_c)
			return (ptr + index);
		index++;
	}
	return (0);
}
