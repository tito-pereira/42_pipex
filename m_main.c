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

/*
abre input
redirect output para pipe
execve (para pipe)
*/
void	cmd_one(int *p1, t_cmd *cmds)
{
	int	*p2;
	int	pid2;
	char	*buff2;
	char	*buff3;

	close(p1[0]); //fecha a leitura, aqui vai ser só escrever para o pipe
	dup2(p1[1], 1); //output é o pipe de escrita
	pid2 = fork()
	if (pid2 == 0)
		execve("cmd1", __environ);
	wait(NULL);
	execve("cmd1", __environ);
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
	t_cmd	*cmds;
	
	if (ac == 5)
	{
		//which command av[2];
		//which command av[3];
		//cmds = proc_cmds(av);
		in = open(av[1], O_RDONLY);
		if (in == -1)
			ft_printf("Error with input file\n");
		p1 = malloc(2 * sizeof(int));
		pipe(p1);
		pid1 = fork();
		if (pid == 0)
			cmd_one(p1, cmds);
		wait(NULL);
		close(in);
		close(p1[1]);
		read(p1[0]);
		out = open(av[4], O_RDWR, O_CREAT);
		if (out == -1)
			ft_printf("Error with output file\n");
		write(out);
		close (out);
		free(p1);
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
	//char	**arr;
	struct s_cmd	*next;
}	t_cmd;

char	*arr[] = {path, input, flags, NULL};

typedef struct s_all {
	char	*file1;
	t_cmd	*cmds;
	char	*file2;
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

mandatory:
make_pipe();

bonus:
while (pipe_nmb > 0) {
	make_pipe();
	pipe_nmb--;
}

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

preciso de fork() para execve() os comandos
uso pipes() para transmitir data um entre o outro
(strings, arrays, etc)
como faço execve disso?

redireciono o output para um fifo?
*/