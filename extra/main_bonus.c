/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:22:03 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/28 15:50:22 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

	all = NULL;
	if (ac >= 5)
	{
		all = proc_central(all, ac, av);
		in = open(all->file1, O_RDONLY);
		if (open_error(in, all) == 1)
			return (0);
		first_cmd(all, in);
		while (all->pipe_nmb > 0)
		{
			first_cmd(all, all->input);
			all->pipe_nmb--;
		}
		last_cmd(all);
		free_all (all);
	}
	else
		ft_printf("Number of files and commands is wrong\n");
	return (0);
}
