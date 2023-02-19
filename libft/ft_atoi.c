/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:51:24 by oburato           #+#    #+#             */
/*   Updated: 2022/05/17 02:53:54 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sinal(size_t num, int sinal)
{
	if (sinal % 2 == 1)
		return ((num /= 10) * -1);
	return (num /= 10);
}

static const char	*ft_check_spaces(const char *str, int *sinal)
{
	while (*str == ' '
		|| *str == '\n'
		|| *str == '\r'
		|| *str == '\f'
		|| *str == '\v'
		|| *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sinal = 1;
		str++;
	}
	if (*str >= '0' && *str <= '9')
		return (str);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		index;
	int		sinal;
	size_t	num;

	index = 0;
	sinal = 0;
	num = 0;
	while (str[index] != '\0')
	{
		str = ft_check_spaces(str, &sinal);
		if (str == 0)
			return (0);
		while (str[index] >= '0' && str[index] <= '9')
		{
			num = (num + (str[index] - '0')) * 10;
			if (str[index + 1] < '0' || str[index + 1] > '9')
			{
				return (ft_check_sinal(num, sinal));
			}
			index++;
		}
		index++;
	}
	return (0);
}
