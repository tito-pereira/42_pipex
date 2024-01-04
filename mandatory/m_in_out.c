/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_in_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:16 by tibarbos          #+#    #+#             */
/*   Updated: 2024/01/04 13:08:32 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(t_all *all, int in)
{
	int	*fd;
	int	pid;

	fd = malloc(2 * sizeof(int));
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close (fd[0]);
		dup2(in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(in);
		close(fd[1]);
		execve(all->cmds->arr[0], all->cmds->arr, ENV_VAR);
	}
	wait(NULL);
	close (fd[1]);
	all->cmds = all->cmds->next;
	all->input = fd[0];
	close (in);
	free(fd);
}

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
		close(all->input);
		close(out);
		execve(all->cmds->arr[0], all->cmds->arr, ENV_VAR);
	}
	wait(NULL);
	close (all->input);
	close (out);
}
