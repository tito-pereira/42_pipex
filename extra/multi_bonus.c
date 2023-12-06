/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:53 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/06 15:23:36 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*
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
*/

void	mult_pipes(t_all *all)
{
	int	pid;
	int	*p2;

	while (all->pipe_nmb > 0)
	{
		p2 = malloc(2 * sizeof(int));
		pipe(p2);
		pid = fork();
		if (pid == 0)
		{
			dup2(all->input, STDIN_FILENO); //fecha-o depois, fim pipe antigo
			dup2(p2[1], STDOUT_FILENO); //fecha-o depois
			close(p2[0]); //nao vou ler deste, posso fechar
			close(p2[1]); //ja foi dupped, posso fechar
			execve(all->cmds->arr[0], all->cmds->arr, ENV_VAR);
		}
		wait(NULL);
		close(p2[1]);
		all->cmds = all->cmds->next;
		all->pipe_nmb--;
		all->input = p2[0];
		free(p2);
	}
}
//falta a troca de pipes, mallocs, frees, etc
//mudar o malloc para onde p1 aponta

/*
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

talvez 2 way pipes
função exec() tem que both ler + write entao é preciso dois
pipes simultaneos
ou nao, as permissoes batem certo, acho que dá
preciso de fork() para execve() os comandos
uso pipes() para transmitir data um entre o outro
(strings, arrays, etc)
como faço execve disso?
*/