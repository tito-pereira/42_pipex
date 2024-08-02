/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:26:33 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:40:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s2[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	if (size > 0)
	{
		while (s2[i] != '\0' && i < (size - 1))
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (j);
}
