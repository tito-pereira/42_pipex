/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:40 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/26 18:00:13 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**new_arr(char **arr)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	while (arr[i] != NULL)
		i++;
	new = malloc((i + 1) * sizeof(char *));
	j = 0;
	while (j < i)
	{
		new[j] = arr[j];
		j++;
	}
	new[i] = NULL;
	free(arr);
	return (new);
}

t_cmd	*proc_cmds(t_all *all, char **av, int index)
{
	t_cmd	*new;
	t_cmd	*begin;
	int		i;

	new = malloc(sizeof(t_cmd));
	new->arr = ft_split(av[index], ' ');
	new->arr = new_arr(new->arr);
	new->arr[0] = proc_which(new->arr[0]);
	begin = new;
	i = all->pipe_nmb;
	while (i >= 0)
	{
		index++;
		new->next = malloc(sizeof(t_cmd));
		new = new->next;
		new->arr = ft_split(av[index], ' ');
		new->arr = new_arr(new->arr);
		new->arr[0] = proc_which(new->arr[0]);
		new->next = NULL;
		i--;
	}
	return (begin);
}

t_all	*proc_all(char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->file1 = av[1];
	all->file2 = av[4];
	all->pipe_nmb = 0;
	all->append = 0;
	all->multi = 0;
	all->input = -1;
	all->cmds = proc_cmds(all, av, 2);
	return (all);
}
