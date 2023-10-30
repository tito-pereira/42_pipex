/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:00 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/30 14:49:14 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_read(int fd, char *buff)
{
	int	ret;

	ret = 1;
	while (ret != 0)
		ret = read(fd, buff, INT_MAX);
}

void	two_exec(int *p2, char *buff2)
{
	char	*buff3;

	close(p2[0]);
	buff3 = execve(buff2);
	//execve();
	write(p2[1], buff3);
	free(buff2);
	close(p2[1]);
}

void	one_exec(int *p1, char *buff1)
{
	int	*p2;
	int	pid2;
	char	*buff2;
	char	*buff3;

	close(p1[0]);
	buff2 = execve(buff1);
	p2 = malloc(2 * sizeof(int));
	pipe(p2);
	pid2 = fork()
	if (pid2 == 0)
		two_exec(p2, buff2);
	wait(NULL);
	close(p2[1]);
	ft_read(p2[0], buff3);
	close(p2[0]);
	write(p1[1], buff3);
	close(p1[1]);
	free(p2);
}

int	main(int ac, char **av)
{
	int	in;
	int	out;
	int	pid1;
	int	*p1;
	char	*buff1;
	
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
		in = open(av[1], O_RDONLY);
		ft_read(in, buff1);
		close(in);
		p1 = malloc(2 * sizeof(int));
		pipe(p1);
		pid1 = fork();
		if (pid == 0)
			do_exec(p1, buff1);
		wait(NULL);
		close(p1[1]);
		read(p1[0]);
		out = open(av[4], O_RDWR, O_CREAT);
		write(out);
		close (out);
		free(p1);
	}
	else
		ft_printf("Please input correct arguments or commands.\n");
}