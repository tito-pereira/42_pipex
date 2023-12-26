/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:22:03 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/26 17:28:24 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		main(int ac, char **av)
{
	int 	in;
	t_all 	*all;

	all = NULL;
	if (ac >= 5)
	{
		all = proc_central(all, ac, av);
		in = open(all->file1, O_RDONLY);
		first_cmd(all, in);
		ft_printf("i am using the bonus main\npipe nmb = %d\n", all->pipe_nmb);
		while (all->pipe_nmb > 0)
		{
			ft_printf("loop\n");
			first_cmd(all, all->input);
			all->pipe_nmb--;
		}
		last_cmd(all);
	}
	else
		ft_printf("Number of files and commands is wrong\n");
	return(0);
}
