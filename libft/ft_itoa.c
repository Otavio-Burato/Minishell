/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:34:09 by oburato           #+#    #+#             */
/*   Updated: 2022/05/07 19:23:37 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(size_t n, size_t len)
{
	if (n > 9)
		return (ft_num_len(n / 10, len + 1));
	return (len);
}

static void	ft_num_put_chr(char *str, long n)
{
	if (n > 9)
		ft_num_put_chr(str - 1, n / 10);
	*str = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n_long;
	size_t	len;

	n_long = (long)n;
	if (n < 0)
		n_long = -n_long;
	len = ft_num_len(n_long, 1);
	if (n < 0)
		len++;
	str = (char *) malloc (len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		*str = '-';
	ft_num_put_chr(str + len -1, n_long);
	*(str + len) = '\0';
	return (str);
}
