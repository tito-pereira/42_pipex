/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:31:19 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/06 16:24:22 by tibarbos         ###   ########.fr       */
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
# include <limits.h> //acho que nao preciso?
# include "../libft/mylib.h" //usar no read

# define LIMITER    "LIM"
# define ENV_VAR    __environ
# define PATH       __environ[32] //nao estou a usar isto

typedef struct s_cmd {
	char	**arr;
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
}	t_all;

// free, errors
void	free_all(t_all *all);
// proc mandatory
t_cmd	*proc_cmds(char **av, int index_a, int index_b);
t_all	*proc_all(char **av);
// first, last
void	first_cmd(t_all *all, int in);
void	last_cmd(t_all *all);

#endif

	//char	*cmd; //so e usado para o which
	//char	*wch; //passo intermedio de formar o path
	//char	*path; //posso usar apenas arr[0]
	//char	**flag;