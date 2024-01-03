/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:00 by tibarbos          #+#    #+#             */
/*   Updated: 2024/01/03 17:11:22 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_error(int in, t_all *all)
{
	if (in == -1)
	{
		free_all (all);
		ft_printf("Incorrect input file.\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		in;
	t_all	*all;

	if (ac == 5)
	{
		all = proc_all(av);
		if (all == NULL)
			return (0);
		in = open(all->file1, O_RDONLY);
		if (open_error(in, all) == 1)
			return (0);
		first_cmd(all, in);
		last_cmd(all);
		free_all (all);
	}
	else
		ft_printf("Number of files and commands is wrong\n");
}
