/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_in_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:16 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/06 15:19:26 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
