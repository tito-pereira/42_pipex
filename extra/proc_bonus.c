/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:47 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/26 17:29:05 by tibarbos         ###   ########.fr       */
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
	ft_printf("lets find the string\nraw:%s\nlim:%s\n", str, lim);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == lim[j])
		{
			ft_printf("its a match\n");
			j++;
			if (lim[j] == '\0')
			{
				ft_printf("return conditions\n");
				ret = ft_substr(str, 0, i);
				ft_printf("ret:%s,\n", ret);
				free (str);
				return (ret);
			}
		}
		ft_printf("loop no %d\n", i);
		i++;
	}
	return (NULL);
}

/*
nao entra nas return conditions
porque o while nao bate certo
tenho que por o if depois do contador de j++,
senao sai do while sem fazer a condicao de retorno

char	*proc_delim(char *lim)
{
	char	*shovel;
	char	*chest;
	char	*total;
	int		r;

	r = 1;
	total = NULL;
	ft_printf("inside reading function\n");
	while (r > 0)
	{
		ft_printf("loop\n");
		chest = ft_strdup(total);
		shovel = malloc(2 * sizeof(char));
		r = read(STDIN_FILENO, shovel, 1);
		shovel[1] = '\0';
		free (total);
		total = ft_strjoin(shovel, chest); //o join da malloc do retorno, mas nao da free dos args
		free(shovel);
		free(chest);
		if (ft_str_find(chest, lim) != NULL)
			return (ft_str_find(total, lim));
	}
	return (NULL);
}*/

char	*proc_delim(char *lim)
{
	char	*chest;

	chest = malloc(1000 * sizeof(char));
	read(STDIN_FILENO, chest, 1000);
	//if (ft_str_find(chest, lim) != NULL)
	return (ft_str_find(chest, lim));
	//free (chest);
	//return (NULL);
}
//dar free do chest na strfind
//ta a retornar NULL
/*
a primeira vez que faco o chest, ja da free
e portanto a segunda vez, no retorno, tem um
chest vazio
*/

t_all	*init_all(t_all *all, int ac, char **av)
{
	all->file1 = av[1];
	all->file2 = av[ac - 1];
	all->append = 0;
	all->pipe_nmb = 0;
	all->multi = 0;
	all->input = -1;
	all->cmds = NULL;
	return(all);
}

int		comp_here_doc(char *av)
{
	//ft_printf("entered the here_doc comparer\n");
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
	if (comp_here_doc(av[1]) == 1) //com append
	{
		//ft_printf("will change to append mode\n");
		all->append = 1;
		all->file1 = proc_delim(av[2]); //esta função vai ler
	}
	if (ac > 6)
	{
		all->multi = 1;
		all->pipe_nmb = ac - 5 - all->append;
	}
	ft_printf("input: %s\n", all->file1);
	ft_printf("pipe_nmb: %d\n", all->pipe_nmb);
	if (all->append == 1)// && ac == 6)
		all->cmds = proc_cmds(all, av, 3);
	else
		all->cmds = proc_cmds(all, av, 2);
	//all->cmds = proc_cmds(all, av, 2); for all
	return (all);
}

/*
colocar mensagem de erro para quando proc delim da erro

//pipe_nmb ta a ficar um short e nao faz o ultimo comando
tinha -5 meti -4 agora
titulo, file1, comando 1 sem pipe, file2 - 4, nao 5
so e 5 se houver heredoc
titulo, heredoc, limiter, etc
*/