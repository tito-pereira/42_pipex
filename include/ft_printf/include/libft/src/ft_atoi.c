/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:26:01 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 13:59:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	tmp;
	int	sign;

	i = 0;
	sign = 1;
	tmp = 0;
	while (((char *)str)[i] == ' '
		|| (((char *)str)[i] >= 9 && ((char *)str)[i] <= 13))
		i++;
	if (((char *)str)[i] == '-' || ((char *)str)[i] == '+')
	{
		if (((char *)str)[i] == '-')
			sign *= -1;
		i++;
	}
	while (((char *)str)[i] >= '0' && ((char *)str)[i] <= '9')
	{
		tmp = (tmp * 10) + (((char *)str)[i] - 48);
		i++;
	}
	return (sign * tmp);
}

unsigned long long	ft_atol(const char *str)
{
	size_t				i;
	unsigned long long	nb;

	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	return (nb);
}
