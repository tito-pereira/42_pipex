/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:49:11 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:40:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (((char *)s)[i] != '\0')
		i++;
	if (((char *)s)[i] == (unsigned char)c)
		return (((char *)s) + i);
	while (i)
	{
		i--;
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((char *)s) + i);
	}
	return (NULL);
}
