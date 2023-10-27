/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:00 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/27 17:37:12 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int	fd1;
	int	fd2;
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
		fd2 = open(av[4], O_RDWR, O_CREAT);
		pipe({fd2, fd1});
		//definir se uso flags para append ou para exclude o que ta la dentro
		//consoante o bonus ou nao
		/*
		acho que tou a fazer isto mal, pipe e usado p comunicar entre processos
		e nao entre files
		*/
		pid = fork();
		/*
		child process so comeca a correr daqui, nao faz a leitura nem o pipe,
		mas tem essas variaveis guardadas
		*/
		if (pid == 0)
			do_exec();
		wait(NULL);
		close (fd1);
		errno;
		ECHILD;
	}
	else
		ft_printf("Please input correct arguments or commands.\n");
}