/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:57 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:40:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int size)
{
	while ((*s1 != '\0' || *s2 != '\0') && *s1 == *s2 && size > 0)
	{
		s1++;
		s2++;
		size--;
	}
	if (size == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
