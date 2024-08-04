/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specs_r2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:34:00 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:27:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	p_u_spec_left(unsigned int tmp, t_pain bois, char pad)
{
	int		c;
	char	*ito;

	c = 0;
	ito = ft_long_itoa(tmp);
	ito = p_null_support(tmp, &bois, ito);
	while (bois.psize-- > 0)
		c = c + ft_putchar_c('0');
	c = c + ft_putstr_c(ito);
	while (bois.size-- > 0)
		c = c + ft_putchar_c(pad);
	free (ito);
	return (c);
}

int	p_x_spec_space_f(unsigned int tmp, t_pain bois, char pad, char f1)
{
	int		c;
	char	*ito;

	c = 0;
	ito = ft_hx_itoa(tmp);
	ito = p_null_support(tmp, &bois, ito);
	if (f1 == '#' && tmp > 0)
		bois.size = bois.size - 2;
	while (bois.size-- > 0)
		c = c + ft_putchar_c(pad);
	if (f1 == '#' && tmp > 0)
		c = c + ft_putstr_c("0x");
	while (bois.psize-- > 0)
		c = c + ft_putchar_c('0');
	c = c + ft_putstr_c(ito);
	free (ito);
	return (c);
}

int	p_x_spec_space_m(unsigned int tmp, t_pain bois, char pad, char f1)
{
	int		c;
	char	*ito;

	c = 0;
	ito = ft_hx_itoa(tmp);
	ito = p_null_support(tmp, &bois, ito);
	if (f1 == '#' && tmp > 0)
	{
		c = c + ft_putstr_c("0x");
		bois.size = bois.size - 2;
	}
	while (bois.psize-- > 0)
		c = c + ft_putchar_c('0');
	c = c + ft_putstr_c(ito);
	while (bois.size-- > 0)
		c = c + ft_putchar_c(pad);
	free (ito);
	return (c);
}

int	p_bx_spec_space_f(unsigned int tmp, t_pain bois, char pad, char f1)
{
	int		c;
	char	*ito;

	c = 0;
	ito = ft_hbx_itoa(tmp);
	ito = p_null_support(tmp, &bois, ito);
	if (f1 == '#' && tmp > 0)
		bois.size = bois.size - 2;
	while (bois.size-- > 0)
		c = c + ft_putchar_c(pad);
	if (f1 == '#' && tmp > 0)
		c = c + ft_putstr_c("0X");
	while (bois.psize-- > 0)
		c = c + ft_putchar_c('0');
	c = c + ft_putstr_c(ito);
	free (ito);
	return (c);
}

int	p_bx_spec_space_m(unsigned int tmp, t_pain bois, char pad, char f1)
{
	int		c;
	char	*ito;

	c = 0;
	ito = ft_hbx_itoa(tmp);
	ito = p_null_support(tmp, &bois, ito);
	if (f1 == '#' && tmp > 0)
	{
		c = c + ft_putstr_c("0X");
		bois.size = bois.size - 2;
	}
	while (bois.psize-- > 0)
		c = c + ft_putchar_c('0');
	c = c + ft_putstr_c(ito);
	while (bois.size-- > 0)
		c = c + ft_putchar_c(pad);
	free (ito);
	return (c);
}