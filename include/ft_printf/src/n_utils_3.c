/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_utils_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:10:47 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:26:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_c(int n, int *c)
{
	if (n == -2147483648)
	{
		ft_putstr("-2");
		(*c) += 2;
		ft_putnbr_c(147483648, c);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		(*c)++;
		n *= -1;
		ft_putnbr_c(n, c);
	}
	else if (n > 9)
	{
		ft_putnbr_c((n / 10), c);
		ft_putnbr_c((n % 10), c);
	}
	else
	{
		ft_putchar(n + 48);
		(*c)++;
	}
}

void	ft_putnbr_pos(int n, int *c)
{
	if (n == -2147483648)
	{
		ft_putchar('2');
		(*c)++;
		ft_putnbr_pos(147483648, c);
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putnbr_pos(n, c);
	}
	else if (n > 9)
	{
		ft_putnbr_pos((n / 10), c);
		ft_putnbr_pos((n % 10), c);
	}
	else
	{
		ft_putchar(n + 48);
		(*c)++;
	}
}
