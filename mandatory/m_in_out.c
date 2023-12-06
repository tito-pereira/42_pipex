#include "pipex.h"

/*
-> pipe entre main process (fd[0]) e first child process (fd[1]);
-> primeiro dup2(fd[1], 1) + execve();
-> retornar fd[0] para ser lido e usado pelo main process depois

(all *)cmds
*all.*cmds.*(arr + 0)
*/

//introduzir o file1 como input no dup2

//all->cmds->path n existe?
//será que é o arr[0] ou preciso de voltar a incluir um path???

/*
-> dependendo de bonus ou nao, faz open() c flags diferentes
-> pega no fd[0] do ultimo comando, usa-o como input
-> pega no file2/argv[5], usa-o como output
*/

void	print_ar(char **arr) {
	int	i = 0;
	while (arr[i] != NULL)
		i++;
	ft_printf("---------------\nthe array has %d elements\n", i);
	int	j = 0;
	while (j <= i) {
		ft_printf("arr[%d]:%s\n", j, arr[j]);
		j++;
	}
}

void	first_cmd(t_all *all, int in)
{
	//-int	*fd;
	int	pid;
	int	half;

	half = open("half.txt", O_RDWR | O_CREAT, 0777);
	//-fd = malloc(2 * sizeof(int));
	//-pipe(fd);
	//if (pipe(p1) == -1)
		//man_error(1, p1, all);
	ft_printf("inside first command, fd: %d\n", in);
	pid = fork();
	//if (pid == -1)
		//man_error(2, p1, all);
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO); //file de input, acho que fecha automatico
		dup2(half, STDOUT_FILENO); //output é o pipe de escrita
		close(in); //fecha a leitura, aqui vai ser só escrever para o pipe
		close(half); //ja dupliquei entao fecho
		execve(all->cmds->arr[0], all->cmds->arr, __environ);
	}
	wait(NULL);
	//-close(fd[1]);
	//all->cmds = all->cmds->next; //passa para o ultimo/proximo cmds
	//print_ar(all->cmds->arr);
	ft_printf("arr[0]: %s\n", all->cmds->arr[0]);
	all->input = 0; //vai dar carry over de leitura para outro sitio
	close (in);
	close (half);
	ft_printf("final reading fd: %d\n", half);
	//-free(fd); //NAO POSSO, ou posso? afinal sim
}

///////////////////////////////////////////////////////////////

void	last_cmd(t_all *all)
{
	int	pid;
	int	out;

	out = 0;
	all->input = open("half.txt", O_RDWR | O_CREAT, 0777);
	ft_printf("inside last cmd, input fd:%d\n", all->input);
	if (all->append == 0) {
		ft_printf("%s is getting reset\n", all->file2);
		out = open(all->file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	else if (all->append == 1) {
		ft_printf("%s will append\n", all->file2);
		out = open(all->file2, O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	if (out == -1) {
		perror("Error with output file\n");
		//exit(EXIT_FAILURE);
	}
	//print_ar(all->cmds->arr);
	ft_printf("arr[0]:%s; out fd:%d\n", all->cmds->arr[0], out);
	pid = fork();
	if (pid == 0)
	{
		dup2(all->input, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(all->input); //dou close na mesma porque eu clonei
		close(out); //e fiquei com 2 fd para cada
		execve(all->cmds->arr[0], all->cmds->arr, __environ);
	}
	wait(NULL);
	close (all->input);
	close (out);
}
//verificar se as flags estão bem e são mesmo estas

/*
-> primeiro testar o meu comando
. wc -l, cmds->next, etc

-> so depois resolver esta questao do file pointer???
*/