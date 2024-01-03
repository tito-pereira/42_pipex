/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:31:19 by tibarbos          #+#    #+#             */
/*   Updated: 2024/01/03 18:43:17 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
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

void	free_all(t_all *all);
void	free_cmds(t_cmd *cmds, int flag);
void	free_arr(char **arr, int flag);
t_cmd	*proc_cmds(t_all *all, char **av, int index);
t_all	*proc_all(char **av);
char	*proc_which(char *arr_zero);
void	first_cmd(t_all *all, int in);
void	last_cmd(t_all *all);

#endif
