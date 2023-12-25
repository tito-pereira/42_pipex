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
multi pipes, tenho que ver qual o file descriptor que tem que
sobrar depois de cada pipe, e tenho que usar o pipe_nmb
while (all->pipe_nmb > 0) {
	all->pipe_nmb--;
}

agora a questão é, proc all ou proc central?
e o all leva malloc dentro da proc central?
ah ya falta fazer agora multiplos pipes
first
multi pipes
last

void	first_cmd(t_all *all, int in)
{
	int	*fd;
	int	pid;

	fd = malloc(2 * sizeof(int));
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(in); //fecha a leitura, aqui vai ser só escrever para o pipe
		ft_printf("3\n");
		close(fd[1]); //ja dupliquei entao fecho
		ft_printf("just print something i am trying to test this\n");
		ft_printf("4\n");
		execve(all->cmds->arr[0], all->cmds->arr, ENV_VAR);
		ft_printf("5\n");
	}
	wait(NULL);
	close(fd[1]);
	all->cmds = all->cmds->next;
	all->input = fd[0];
	close (in);
	close (fd[1]);
	free(fd);
}

void	last_cmd(t_all *all)
{
	int	pid;
	int	out;

	out = 0;
	if (all->append == 0)
		out = open(all->file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (all->append == 1)
		out = open(all->file2, O_WRONLY | O_CREAT | O_APPEND, 0777);
	pid = fork();
	if (pid == 0)
	{
		dup2(all->input, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(all->input); //dou close na mesma porque eu clonei
		close(out); //e fiquei com 2 fd para cada
		execve(all->cmds->arr[0], all->cmds->arr, ENV_VAR);
	}
	wait(NULL);
	close (all->input);
	close (out);
}

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