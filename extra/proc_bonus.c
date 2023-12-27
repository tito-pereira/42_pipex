/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:47 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/27 13:12:44 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_str_find(char *str, char *lim)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == lim[j])
		{
			j++;
			if (lim[j] == '\0')
			{
				ret = ft_substr(str, 0, i);
				free (str);
				return (ret);
			}
		}
		i++;
	}
	return (NULL);
}

char	*proc_delim(char *lim)
{
	char	*chest;

	chest = malloc(1000 * sizeof(char));
	chest = read(STDIN_FILENO, chest, 1000);
	if (chest == NULL)
		return (NULL);
	return (ft_str_find(chest, lim));
}

t_all	*init_all(t_all *all, int ac, char **av)
{
	all->file1 = av[1];
	all->file2 = av[ac - 1];
	all->append = 0;
	all->pipe_nmb = 0;
	all->multi = 0;
	all->input = -1;
	all->cmds = NULL;
	return (all);
}

int	comp_here_doc(char *av)
{
	if (ft_strlen(av) == 8)
	{
		if (av[0] == 'h' && av[1] == 'e' && av[2] == 'r' && av[3] == 'e'
			&& av[4] == '_' && av[5] == 'd' && av[6] == 'o' && av[7] == 'c')
			return (1);
	}
	return (0);
}

t_all	*proc_central(t_all *all, int ac, char **av)
{
	all = malloc(sizeof(t_all));
	all = init_all(all, ac, av);
	if (comp_here_doc(av[1]) == 1)
	{
		all->append = 1;
		all->file1 = proc_delim(av[2]);
	}
	if (ac > 6)
	{
		all->multi = 1;
		all->pipe_nmb = ac - 5 - all->append;
	}
	if (all->append == 1)
		all->cmds = proc_cmds(all, av, 3);
	else
		all->cmds = proc_cmds(all, av, 2);
	return (all);
}
