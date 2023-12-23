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
void	first_cmd(t_all *all, int in)
{
	int	*fd;
	int	pid;
	//int	half;

	//half = open("half.txt", O_RDWR | O_CREAT, 0777);
	fd = malloc(2 * sizeof(int));
	pipe(fd);
	//if (pipe(fd) == -1)
		//man_error(1, p1, all);
	ft_printf("inside first command, fd: %d\n", in);
	ft_printf("error here?\n");
	pid = fork();
	ft_printf("or maybe here?\n");
	//if (pid == -1)
		//man_error(2, p1, all);
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO); //file de input, acho que fecha automatico
		dup2(fd[1], STDOUT_FILENO); //output é o pipe de escrita
		close(in); //fecha a leitura, aqui vai ser só escrever para o pipe
		close(fd[1]); //ja dupliquei entao fecho
		execve(all->cmds->arr[0], all->cmds->arr, ENV_VAR);
	}
	wait(NULL);
	close(fd[1]);
	all->cmds = all->cmds->next; //passa para o ultimo/proximo cmds
	//print_ar(all->cmds->arr);
	ft_printf("arr[0]: %s\n", all->cmds->arr[0]);
	all->input = fd[0]; //vai dar carry over de leitura para outro sitio
	close (in);
	close (fd[1]);
	ft_printf("final reading fd: %d\n", fd[0]);
	free(fd); //NAO POSSO, ou posso? afinal sim
}

void	last_cmd(t_all *all)
{
	int	pid;
	int	out;

	out = 0;
	//all->input = open("half.txt", O_RDWR | O_CREAT, 0777);
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
		execve(all->cmds->arr[0], all->cmds->arr, ENV_VAR);
	}
	wait(NULL);
	close (all->input);
	close (out);
}

ver o que "vem" do first comand para entrar no multi pipes
e para voltar a sair do multi pipes e entrar no last cmd
*/

////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////

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

/*
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
*/
//falta a troca de pipes, mallocs, frees, etc
//mudar o malloc para onde p1 aponta

