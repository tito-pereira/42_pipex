/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:54 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/27 18:08:47 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free (arr[i]);
		i++;
	}
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
	free (cmds);
}

void	free_all(t_all *all)
{
	if (all->append == 1)
		free (all->file1);
	free_cmds (all->begin);
	free (all);
}

/*
o free file1 e por causa de ler do terminal
faco um malloc extra
se nao for aqui, e no proc cmds
*/