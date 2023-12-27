/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:54 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/27 15:37:10 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while(arr[i] != NULL)
	{
		free (arr[i]);
		i++;
	}
	if (arr[i] == NULL)
		free (arr[i]);
	free (arr);
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*tmp;
	
	while (cmds != NULL)
	{
		tmp = cmds;
		free_arr (tmp->arr);
		cmds = cmds->next;
		free (tmp);
	}
	if (cmds == NULL)
		free_arr (cmds->arr);
	free (cmds);
}

void	free_all(t_all *all)
{
	free (all->file1);
	free (all->file2);
	free_cmds (all->begin);
	//free_cmds (all->cmds);
	free (all);
}

/*t_all	*proc_all(char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->file1 = av[1];
	all->file2 = av[4];
	all->pipe_nmb = 0;
	all->append = 0;
	all->multi = 0;
	all->input = -1;
	//free (all->cmds);
	all->cmds = proc_cmds(all, av, 2);
	all->begin = all->cmds;
	return (all);
}*/

/*
free all
free struct t_cmds
free array c os comandos

o commands itera-se na execucao
logo os que ficam para tras nao sao apagados
posso criar um all->begin c o primeiro comando inalterado

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

acho que o free all esta bem
simplesmente tem segfault de double free e nao chega la
*/