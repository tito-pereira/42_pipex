/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:00 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/27 16:45:20 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int	fd1;
	int	pid;
	
	if (ac == 5)
	{
		if (av[1] == "here_doc")
		{
			while (buff[] != LIMITER)
			{
				read(1, buff, 1);
			}
			av[1] == buff;
		}
		fd1 = open(av[1], O_RDONLY);
		pid = fork();
		if (pid == 0)
			do_exec();
		wait(NULL);
		close (fd1);
	}
	else
		ft_printf("Please input correct arguments or commands.\n");
}