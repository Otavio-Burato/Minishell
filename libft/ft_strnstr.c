/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 05:41:26 by oburato           #+#    #+#             */
/*   Updated: 2022/05/01 13:43:18 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	index;

	index = 0;
	len_little = ft_strlen(little);
	if (!len_little)
		return ((char *)big);
	while (big[index] != '\0' && len_little <= len)
	{
		if (ft_strncmp(&big[index], little, len_little) == 0)
			return ((char *)&big[index]);
		index++;
		len--;
	}
	return (NULL);
}
