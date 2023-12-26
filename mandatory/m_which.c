/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_which.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:59:32 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/26 18:00:18 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*read_pipe(int fd)
{
	char	*total;
	int		err;

	err = 100;
	total = malloc(100 * sizeof(char));
	while (err == 100)
	{
		err = read(fd, total, 100);
		if (err == 0)
			break ;
	}
	total[err - 1] = '\0';
	return (total);
}

void	exec_which(int *fd, char **tmp)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve("/usr/bin/which", tmp, ENV_VAR);
}

char	*proc_which(char *arr_zero)
{
	char	*total;
	char	**tmp;
	int		*fd;
	int		pid;

	fd = malloc(2 * sizeof(int));
	pipe(fd);
	tmp = malloc(3 * sizeof(char *));
	tmp[0] = "/usr/bin/which";
	tmp[1] = arr_zero;
	tmp[2] = NULL;
	pid = fork();
	if (pid == 0)
		exec_which(fd, tmp);
	wait(NULL);
	free(tmp);
	close(fd[1]);
	total = read_pipe(fd[0]);
	close(fd[0]);
	free(fd);
	return (total);
}
