/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:00:47 by oburato           #+#    #+#             */
/*   Updated: 2022/05/01 13:42:47 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	int	index;

	index = 0;
	if (dest < src)
	{
		while (n--)
		{
			((char *)dest)[index] = ((char *)src)[index];
			index++;
		}
	}
	else
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
