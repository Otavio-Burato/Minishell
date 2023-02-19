/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:38 by oburato           #+#    #+#             */
/*   Updated: 2022/04/30 21:15:57 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ptr;
	char	cha;

	index = 0;
	cha = c;
	ptr = (char *)s;
	while (s[index] != '\0')
	{
		if (s[index] == cha)
			return (ptr + index);
		index++;
	}
	if (s[index] == '\0' && cha == '\0')
		return (((char *)(s + index)));
	return (NULL);
}
