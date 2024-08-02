/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:53:26 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:33:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*bbc;
	size_t	len;
	size_t	i;

	i = 0;
	len = num * size;
	bbc = malloc(len);
	if (!bbc)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)bbc)[i] = '\0';
		i++;
	}
	return (bbc);
}
