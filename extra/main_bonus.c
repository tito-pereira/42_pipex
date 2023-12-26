/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:22:03 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/26 16:03:49 by tibarbos         ###   ########.fr       */
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

/*
nao entra no loop porque o pipe nmb fica a zeros

o problema nao e da funcao open porque funciona no normie
e faz truncate
o problema e algo do bonus mesmo
o numero de pipes e correto
o numero de loops e correto
talvez a funcao que seja errada
ou o proc cmds

proc cmds ta bem
e algo na first cmd
ja sei, a first cmd nao deve suportar multiplos files
tava a fazer um pipe a mais, entrava no last cmd c cmd NULL
nao sei porque quis decidir ter o normie como pipe 1
voltei a por tudo a zeros e funcionou
*/

/*
multi pipes, tenho que ver qual o file descriptor que tem que
sobrar depois de cada pipe, e tenho que usar o pipe_nmb
while (all->pipe_nmb > 0) {
	all->pipe_nmb--;
}

o importante é o all->input, que representa o file descriptor
que vai servir de input do last command/pipe na reading end
portanto, basear no last comman mas tenho que deixar a reading end [0]?
do output aberta

tenho que confirmar amanha, mas parece me que vou até usar
repetida a "first cmd" function e vou alterando o int in de ficheiro de
input, usando o all->input
- gere bem os file descriptors
- gere bem pipes e forks
- passa para o all->cmds->next 

depois no fim ver a questão do close repetido e falta de close no forked

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