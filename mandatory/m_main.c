/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:00 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/26 17:39:22 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int		in;
	t_all	*all;

	if (ac == 5)
	{
		all = proc_all(av);
		in = open(all->file1, O_RDONLY);
		first_cmd(all, in);
		last_cmd(all);
	}
	else
		ft_printf("Number of files and commands is wrong\n");
}
