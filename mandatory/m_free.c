/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:54 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/27 14:28:30 by tibarbos         ###   ########.fr       */
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
	{
		free_arr (cmds->arr);
		free (cmds);
	}
}

void	free_all(t_all *all)
{
	free (all->file1);
	free (all->file2);
	free_cmds (all->cmds);
	free (all);
}

/*
free all
free struct t_cmds
free array c os comandos

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
}	t_all;

4 mallocs que faltam
2 splits (substrs) (arr antigo)
1 new arr (null no fim?)
1 direto do proc cmds (t_cmds)
*/