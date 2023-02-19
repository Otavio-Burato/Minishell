/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:45:23 by oburato           #+#    #+#             */
/*   Updated: 2022/04/10 23:17:58 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while ((s1[index] != '\0' || s2[index] != '\0') && n--)
	{
		len = ((unsigned char)s1[index] - (unsigned char)s2[index]);
		if (len != 0)
			break ;
		index++;
	}
	return (len);
}
