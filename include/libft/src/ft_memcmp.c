/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:28:18 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:38:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = s1;
	b = s2;
	while (i < n)
	{
		if (a[i] > b[i])
			return (1);
		if (a[i] < b[i])
			return (-1);
		i++;
	}
	return (0);
}
