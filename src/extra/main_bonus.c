/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:22:03 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 18:02:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	null_check(t_all *all)
{
	if (all->cmds == NULL)
	{
		free_all (all);
		exit (0);
	}
}

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
		if (all == NULL)
			return (0);
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
