/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hx_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:46:58 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:25:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned int	ft_hx_set_size(unsigned int n)
{
	unsigned int	counter;
	unsigned int	tmp;

	counter = 1;
	tmp = 1;
	if (n > 0)
	{
		while ((n / tmp) >= 16)
		{
			tmp *= 16;
			counter++;
		}
	}
	return (counter);
}

char	*ft_hx_reverse(char *str)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	tmp;

	i = 0;
	size = 0;
	tmp = 0;
	while (str[size] != '\0')
		size++;
	while (i < (size / 2))
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
	return (str);
}

char	*ft_hx_support(char *ret, unsigned int tmp, \
	unsigned int i, unsigned int n)
{
	unsigned int	k;
	char			b;

	if (n == 0)
		ret[0] = '0';
	while (tmp > 0)
	{
		k = tmp % 16;
		b = check_letter_x(k);
		ret[i] = b;
		tmp = tmp / 16;
		i++;
	}
	return (ret);
}

char	*ft_hx_itoa(unsigned int n)
{
	unsigned int	i;
	unsigned int	tmp;
	char			*ret;

	i = 0;
	tmp = n;
	ret = malloc((ft_hx_set_size(n) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret = ft_hx_support(ret, tmp, i, n);
	ret[ft_hx_set_size(n)] = '\0';
	ft_hx_reverse(ret);
	return (ret);
}
