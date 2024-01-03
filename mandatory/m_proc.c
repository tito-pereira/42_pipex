/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:40 by tibarbos          #+#    #+#             */
/*   Updated: 2024/01/03 17:19:01 by tibarbos         ###   ########.fr       */
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
	free (arr);
	return (new);
}

int	proc_loop(t_cmd *new, char **av, int index, int i)
{
	while (i >= 0)
	{
		index++;
		new->next = malloc(sizeof(t_cmd));
		new = new->next;
		new->arr = ft_split(av[index], ' ');
		new->arr = new_arr(new->arr);
		new->arr[0] = proc_which(new->arr[0]);
		new->next = NULL;
		if (new->arr[0] == NULL)
			return (0);
		i--;
	}
	return (1);
}

t_cmd	*proc_cmds(t_all *all, char **av, int index)
{
	t_cmd	*new;
	t_cmd	*begin;
	int		i;

	new = malloc(sizeof(t_cmd));
	new->next = NULL;
	new->arr = ft_split(av[index], ' ');
	new->arr = new_arr(new->arr);
	new->arr[0] = proc_which(new->arr[0]);
	if (new->arr[0] == NULL)
	{
		free_cmds (new);
		return (NULL);
	}
	begin = new;
	i = all->pipe_nmb;
	if (proc_loop(new, av, index, i) == 0)
	{
		free_cmds (begin);
		return (NULL);
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
	if (all->cmds == NULL)
	{
		free (all);
		return (NULL);
	}
	all->begin = all->cmds;
	return (all);
}

/*
se o proc_which der erro / nao existir comando

. primeiro por a divisao do proc cmds a funcionar
- aparentemente ja ta a dar

. segundo, funcao auxiliar de quando ha erro de comando
	de far os frees necessarios e retornar NULL
dois mains, proc all
erros no proc_which previstos, agr falta testar,
pra ja compila tudo bem

. terceiro, tratar da proc_which, dar free quando erro,
	usar os perror no execve, evitar q entre na read c erro, etc

if (new->arr[0] == NULL) //resultado do proc_which retornar NULL

==141852== Invalid write of size 1
==141852==    at 0x4017BF: read_pipe (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==    by 0x4018D1: proc_which (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==    by 0x4015F5: proc_cmds (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==    by 0x401DEA: proc_central (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==    by 0x401987: main (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==  Address 0x4a5729f is 1 bytes before a block of size 100 alloc'd
==141852==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==141852==    by 0x40177B: read_pipe (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==    by 0x4018D1: proc_which (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==    by 0x4015F5: proc_cmds (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==    by 0x401DEA: proc_central (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852==    by 0x401987: main (in /nfs/homes/tibarbos/42_Cursus/pipex/pipex)
==141852== 

sera que ja esta tudo?? parece??
*/

/*while (i >= 0)
	{
		index++;
		new->next = malloc(sizeof(t_cmd));
		new = new->next;
		new->arr = ft_split(av[index], ' ');
		new->arr = new_arr(new->arr);
		new->arr[0] = proc_which(new->arr[0]);
		new->next = NULL;
		i--;
	}*/