/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:54 by tibarbos          #+#    #+#             */
/*   Updated: 2024/08/02 18:03:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	free_arr(char **arr, int flag)
{
	int	i;

	i = flag;
	if (arr[i] == NULL && arr[i + 1] != NULL)
		i++;
	while (arr[i] != NULL)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

void	free_cmds(t_cmd *cmds, int flag)
{
	t_cmd	*tmp;

	while (cmds != NULL)
	{
		tmp = cmds;
		free_arr (cmds->arr, flag);
		cmds = cmds->next;
		free (tmp);
	}
	free (cmds);
}

void	free_all(t_all *all)
{
	if (all->append == 1)
		free (all->file1);
	free_cmds (all->begin, 0);
	free (all);
}
