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

t_all	*proc_all(char **av)
{
	ez;
	//which command av[2];
	//which command av[3];
	//cmds = proc_cmds(av);, cmds
	//all = proc_all(av, cmds); files
	/*in = open(av[1], O_RDONLY);
	if (in == -1)
		ft_printf("Error with input file\n");
	posso usar o mesmo main para tudo, incluindo o
	all = proc_all e o 
	while (pipe_nmb)
	e apenas mudo o valor do pipe_nmb e o processamento
	do av[1] dentro do proc_all*/
}

void	mult_pipes(t_all *all, int in, int **p1)
{
	int	pid;
	int	*p2;

	while (all->n_pipes > 0)
	{
		p2 = malloc(2 * sizeof(int));
		pid = fork();
		if (pid == 0)
		{
			dup2(p1[0], STDIN_FILENO);
			dup2(p2[1], STDOUT_FILENO);
			close(p2[0]); //nao vou ler deste, posso fechar
			close(p2[1]); //ja foi dupped, posso fechar
			execve(cmd, arr, __environ);
		}
		all->n_pipes--;
		free(p2);
	}
}
//falta a troca de pipes, mallocs, frees, etc
//mudar o malloc para onde p1 aponta

int	main(int ac, char **av)
{
	int		in;
	int		pid1;
	int		*p1;
	t_all	*all;
	
	if (ac == 5)
	{
		all = malloc(sizeof(t_all));
		all = proc_all(av);
		p1 = malloc(2 * sizeof(int));
		pipe(p1);
		pid1 = fork();
		if (pid == 0)
			cmd_one(p1, all);
		wait(NULL);
		close(p1[1]);
		in = p1[0];
		free(p1);
		if (bonus == 1)
			in = mult_pipes(all, in, &p1);
		last_cmd(in, all);
		free_all(all);
	}
	else
		ft_printf("Number of files and commands is wrong\n");
}

typedef struct s_cmd {
	char	*cmd;
	char	*wch;
	char	*path; //path to cmd
	char	*input; //path to input file
	char	**flag;
	char	**arr;
	struct s_cmd	*next;
}	t_cmd;

char	*arr[] = {path, input, flags, NULL};

typedef struct s_all {
	char	*file1;
	t_cmd	*cmds;
	char	*file2;
	int		pipe_nmb; //nº argv - 3
	int		flag; //0 para overwite, 1 para append
	int		bonus; //0 para mandatory, 1 para bonus
}	t_all;

//mandatory, so 4 args (ac == 5)
//bonus, pode ser inumeros ac (here_doc, varios pipes)
/*
-> modular o funcionamento de um só comando
ou de um só pipe
pipe:
input (fd do pipe output anterior)
dup2(new_pipe[1], 1);
execve(cmd, flags, NULL, __environ);
output ()

-----
MANDATORY:
0 * make_pipe();
1 * end_pipe()

BONUS:
x * make_pipe();
1 * end_pipe();
while (pipe_nmb > 0) {
	make_pipe();
	pipe_nmb--;
}
-----

-> adicionar "here_doc" processing à parte
. here_doc substitui o av[1];
(bonus)

-> como coloco o input no execve?
faço execve de (cd "/path/to/input_file") ?
provavelmente sim para alterar primeiro a environ PWD
e depois quando execve() os comandos, passo environ
já com o PWD alterado e faz aquilo que eu quero
(mas assim altera o meu directory permanente, eu quero que
altere só no comando..)
sera que eu no execve consigo especificar o meu caminho de input?
conseguir consigo mas tenho que alterar o environ
ou posso simplesmente passar o "file1" que suponho que seja um pathway
passo isso como primeiro ou ultimo argumento à função "ls" em si xd
easy done (ordem dos args não importa, experimentei agora xd)
uau, posso apenas passar como arg e eu aqui a complicar tudo xd
. como coloco fd do pipe como input?
vou ter que criar um tempo file talvez
mas depois como apago?

file1 + exec1 -> pipe1
pipe1 + exec2 -> file2

mandatory nao vai ter pipes intermedios, vai direto para o output

dup2(pipe[0], STDIN_FILENO);
dup2(file2, STDOUT_FILENO);
execve(cmd2, __environ);

(exec_one)
dup2(p1[1], 1);
execve(cmd1, file1)

(main)
file = p1[0] //permissao de ler

while (pipe_nmb > 0) {
(make_pipe)
dup2(file, 0); //permissao de ler
dup2(p2[1], 1);
execve(cmd);

(main)
file = pipe[0];
pipe_nmb--;
}

pipe[0]

talvez 2 way pipes
função exec() tem que both ler + write entao é preciso dois
pipes simultaneos
ou nao, as permissoes batem certo, acho que dá
preciso de fork() para execve() os comandos
uso pipes() para transmitir data um entre o outro
(strings, arrays, etc)
como faço execve disso?

redireciono o output para um fifo?
redireciono o output para o file2?
e depois uso o file2 como input?
mas e quando for em append_mode?

ja sei..
tenho que dup2(<output>, 0);
*/