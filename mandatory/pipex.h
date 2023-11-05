/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:31:19 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/30 16:10:11 by tibarbos         ###   ########.fr       */
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
# include <limits.h>
# include "../libft/mylib.h" //usar no read

# define LIMITER    "LIM"
# define ENV_VAR    __environ
# define PATH       __environ[32]

typedef struct s_cmd {
	char	*cmd;
	char	*wch;
	char	*path; //path to cmd
	char	*input; //path to input file
	char	**flag;
	char	**arr;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_all {
	char	*file1;
	t_cmd	*cmds;
	char	*file2;
	int		input;
	int		pipe_nmb; //nº argv - 4 (if flag == 1, argv - 5)
	int		append; //0 para overwite, 1 para append
	int		multi; //0 para mandatory, 1 para bonus
}	t_all;

//atencao ao mylib/libft porque ha funcoes auxiliares c o mesmo nome
//se so chamar ft_printf ou getnext na boa, as outras cuidado

// free
void	free_all(t_all *all);
// proc_all
// first, last
void	first_cmd(int *p1, t_all *all);
void	last_cmd(t_all *all, int in);

#endif