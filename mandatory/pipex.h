/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:31:19 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/27 16:39:56 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> //write, read, fork, exec
# include <stdlib.h> //malloc, free
# include <sys/wait.h> //wait, waitpid, getpid, getppid
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> //open
# include "../libft/mylib.h"

# define LIMITER    "LIM"
# define ENV_VAR    __environ

typedef struct s_cmd {
	char			**arr;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_all {
	char	*file1;
	char	*file2;
	int		pipe_nmb;
	int		append;
	int		multi;
	int		input;
	t_cmd	*cmds;
	t_cmd	*begin;
}	t_all;

// free, errors
void	free_all(t_all *all);
void	free_arr(char **arr);
// proc mandatory
t_cmd	*proc_cmds(t_all *all, char **av, int index);
t_all	*proc_all(char **av);
char	*proc_which(char *arr_zero);
// first & last
void	first_cmd(t_all *all, int in);
void	last_cmd(t_all *all);

#endif
