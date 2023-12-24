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
		//multi pipes
		last_cmd(all);
	}
	else
		ft_printf("Number of files and commands is wrong\n");
	return(0);
}

/*
agora a questão é, proc all ou proc central?
e o all leva malloc dentro da proc central?
ah ya falta fazer agora multiplos pipes
first
multi pipes
last

int	main(int ac, char **av)
{
	int		in;
	t_all	*all;
	
	if (ac == 5) //tirar isto no bónus
	{
		all = proc_all(av);
		in = open(all->file1, O_RDONLY);
		first_cmd(all, in);
		last_cmd(all);
	}
	else
		ft_printf("Number of files and commands is wrong\n");
}
*/