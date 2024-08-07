/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_which.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:59:32 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 18:03:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*read_pipe(int fd)
{
	char	*total;
	int		err;

	total = malloc(200 * sizeof(char));
	err = read(fd, total, 150);
	if (err <= 0)
	{
		free (total);
		return (NULL);
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
	free(arr_zero);
	return (total);
}
