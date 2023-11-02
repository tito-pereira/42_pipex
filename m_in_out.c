#include "pipex_h"

void	first_cmd(int *p1, t_all *all)
{
	close(p1[0]); //fecha a leitura, aqui vai ser só escrever para o pipe
	dup2(p1[1], STDOUT_FILENO); //output é o pipe de escrita
	close(p1[1]); //ja dupliquei entao fecho
	execve("cmd1", arr, __environ);
	all->cmds = all->cmds->next;
}

void	last_cmd(t_all *all, int in)
{
	int	pid;
	int	out;

	if (all->bonus == 0)
		out = open(all->file2, O_WRONLY, O_CREAT, O_EXCLUDE);
	else if (all->bonus == 1)
		out = open(all->file2, O_WRONLY, O_CREAT, O_APPEND);
	if (out == -1)
		ft_printf("Error with output file\n");
	pid = fork();
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		execve(all->cmds->path, all->cmds->arr, __environ);
	}
	wait(NULL);
	close(out);
}