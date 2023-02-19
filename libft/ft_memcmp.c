/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:36:24 by oburato           #+#    #+#             */
/*   Updated: 2022/04/24 17:53:14 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	int				len;
	unsigned char	*sc1;
	unsigned char	*sc2;

	index = 0;
	sc1 = ((unsigned char *)s1);
	sc2 = ((unsigned char *)s2);
	if (n == 0)
		return (0);
	while (index < n)
	{
		len = (sc1[index] - sc2[index]);
		if (len)
			return (len);
		index++;
	}
	return (0);
}
