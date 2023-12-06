/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:22:03 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/06 16:00:27 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av)
{
	int		in;
	t_all	*all;
	
	if (ac == 5) //-> normie
	{
		all = proc_all(av);
		in = open(all->file1, O_RDONLY);
		first_cmd(all, in);
        last_cmd(all);
	}
    else if (ac > 5) //bonus
    {
		all = proc_all(av);
		//ft_printf("--- STRUCT ALL CREATED ---\n");
		in = open(all->file1, O_RDONLY);
		//ft_printf("file1 fd: %d\n", in);
		first_cmd(all, in);
		//ft_printf("--- FIRST COMMAND ---\n");
		//ft_printf("carryover fd: %d\n", all->input);
		if (all->append == 1 || all->multi == 1)
			mult_pipes(all);
		//ft_printf("carryover multi fd: %d\n", all->input);
        last_cmd(all);
		//ft_printf("--- LAST COMMAND ---\n");
		//free_all(all);
	}
	else
		ft_printf("Number of files and commands is wrong\n");
}