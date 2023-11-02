#include "pipex_h"

/*
-> pipe entre main process (fd[0]) e first child process (fd[1]);
-> primeiro dup2(fd[1], 1) + execve();
-> retornar fd[0] para ser lido e usado pelo main process depois
*/

void	first_cmd(int *p1, t_all *all)
{
	int	*p1;
	int	pid;

	p1 = malloc(2 * sizeof(int));
	if (pipe(&p1) == -1)
		man_error(1, p1, all);
	pid = fork();
	if (pid == -1)
		man_error(2, p1, all);
	if (pid == 0)
	{
		dup2(p1[1], STDOUT_FILENO); //output é o pipe de escrita
		close(p1[0]); //fecha a leitura, aqui vai ser só escrever para o pipe
		close(p1[1]); //ja dupliquei entao fecho
		execve(all->cmds->path, all->cmds->arr, __environ);
	}
	wait(NULL);
	close(p1[1]);
	all->cmds = all->cmds->next;
	all->input = p1[0];
	free(p1);
}

/*
-> dependendo de bonus ou nao, faz open() c flags diferentes
-> pega no fd[0] do ultimo comando, usa-o como input
-> pega no file2/argv[5], usa-o como output
*/

void	last_cmd(t_all *all)
{
	int	pid;
	int	out;

	if (all->bonus == 0)
		out = open(all->file2, O_WRONLY | O_CREAT | O_TRUNC);
	else if (all->bonus == 1)
		out = open(all->file2, O_WRONLY | O_CREAT | O_APPEND);
	if (out == -1)
		ft_printf("Error with output file\n");
	pid = fork();
	if (pid == 0)
	{
		dup2(all->input, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		execve(all->cmds->path, all->cmds->arr, __environ);
	}
	wait(NULL);
	close(all->input); //acho que automaticamente fecha depois
	close(out); //same, acho que automaticamente fecha depois
}
//verificar se as flags estão bem e são mesmo estas