#include "pipex.h"

/*
-> pipe entre main process (fd[0]) e first child process (fd[1]);
-> primeiro dup2(fd[1], 1) + execve();
-> retornar fd[0] para ser lido e usado pelo main process depois

(all *)cmds
*all.*cmds.*(arr + 0)
*/

void	first_cmd(t_all *all, int in)
{
	int	*p1;
	int	pid;

	p1 = malloc(2 * sizeof(int));
	//if (pipe(p1) == -1)
		//man_error(1, p1, all);
	pid = fork();
	//if (pid == -1)
		//man_error(2, p1, all);
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO); //file de input, acho que fecha automatico
		dup2(p1[1], STDOUT_FILENO); //output é o pipe de escrita
		close(p1[0]); //fecha a leitura, aqui vai ser só escrever para o pipe
		close(p1[1]); //ja dupliquei entao fecho
		execve(all->cmds->arr[0], all->cmds->arr, __environ);
	}
	wait(NULL);
	close(p1[1]);
	all->cmds = all->cmds->next;
	all->input = p1[0];
	free(p1);
}
//introduzir o file1 como input no dup2

//all->cmds->path n existe?
//será que é o arr[0] ou preciso de voltar a incluir um path???

/*
-> dependendo de bonus ou nao, faz open() c flags diferentes
-> pega no fd[0] do ultimo comando, usa-o como input
-> pega no file2/argv[5], usa-o como output
*/

void	last_cmd(t_all *all)
{
	int	pid;
	int	out;

	if (all->append == 0)
		out = open(all->file2, O_WRONLY | O_CREAT | O_TRUNC);
	else if (all->append == 1)
		out = open(all->file2, O_WRONLY | O_CREAT | O_APPEND);
	if (out == -1)
		ft_printf("Error with output file\n");
	pid = fork();
	if (pid == 0)
	{
		dup2(all->input, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		execve(all->cmds->arr[0], all->cmds->arr, __environ);
	}
	wait(NULL);
	close(all->input); //acho que automaticamente fecha depois
	close(out); //same, acho que automaticamente fecha depois
}
//verificar se as flags estão bem e são mesmo estas