/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:14:57 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 12:40:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	i = 0;
	len = ft_strlen(((char *)s));
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (((char *)s)[i] != '\0')
	{
		res[i] = f(i, ((char *)s)[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
