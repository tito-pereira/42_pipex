/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:47 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/06 16:49:26 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/*

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//////////////////////

char	*ft_sup(char *substr, char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start] != '\0' && len > 0)
	{
		substr[i] = s[start];
		start++;
		i++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;

	if (len >= ft_strlen(((char *)s)))
		len = ft_strlen(((char *)s)) - start;
	if (start >= ft_strlen(((char *)s)))
	{
		substr = malloc(1 * sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	else
		substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	substr = ft_sup(substr, ((char *)s), start, len);
	return (substr);
}

//////////////////////

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}*/
/*
parece me que a strjoin junta tudo, strnula ou não
cada strjoin da malloc, preciso de libertar

nao des free do lim
so do chest / total

ver se da strdup de NULL, se retorna NULL

ver se o mecanismo de ler do stdin é este
caso seja, ja acabei o projeto
caso n seja, tenho que refazer só esta parte
amanha testar o bonus 
*/

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
			if (lim[j] == '\0')
			{
				ret = ft_substr(str, 0, i);
				free (str);
				return (ret);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*proc_delim(char *lim)
{
	char	*shovel;
	char	*chest;
	char	*total;
	int		r;

	r = 1;
	total = NULL;
	while (r > 0)
	{
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
}

/*
t_cmd	*proc_cmds(char **av, int index)
{
	t_cmd	*new;
	t_cmd	*begin;

	new = malloc(sizeof(t_cmd));
	new->arr = ft_split(av[index], ' '); //primeiro set de comandos na char **
	new->arr = new_arr(new->arr); //acrescenta o NULL no fim
	new->arr[0] = proc_which(new->arr[0]); //muda o primeiro elemento para PATH
	begin = new;
	while (all->pipe_nmb > 0)
	{
		index++;
		new->next = malloc(sizeof(t_cmd)); //new atualmente == NULL, por isso, dar novo malloc
		new = new->next; //char ** = char ** next
		new->arr = ft_split(av[index], ' '); //segundo set de comandos na char **
		new->arr = new_arr(new->arr); //acrescenta o NULL no fim
		new->arr[0] = proc_which(new->arr[0]); //muda o primeiro elemento para PATH
		new->next = NULL;
		all->pipe_nmb--;
	}
	return(begin);
}*/

t_all	*init_all(t_all *all, int ac, char **av)
{
	all->file1 = av[1];
	all->file2 = av[ac - 1];
	all->append = 0;
	all->pipe_nmb = 1;
	all->multi = 0;
	all->input = -1;
	all->cmds = NULL;
	return(all);
}

int		comp_here_doc(char *av)
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
	if (comp_here_doc(av[1]) == 1) //com append
	{
		all->append = 1;
		all->file1 = proc_delim(av[2]); //esta função vai ler
	}
	if (ac > 6)
	{
		all->multi = 1;
		all->pipe_nmb = ac - 5 - all->append;
	}
	if (all->append == 1 && ac == 6)
		all->cmds = proc_cmds(all, av, 2); //unica situcação q se usa normie
	else
		all->cmds = proc_cmds(all, av, 2); //flag para ver se é append ou nao
	return (all);
}

/*
flag undeclared
here doc nao se pode comparar a pointer
proc_multi_cmds(all, av, 2);
t_cmd	*proc_cmds(t_all *all, char **av, int index);
para além disso, ainda tenho que testar a nova improved
proc cmds, que serve tanto para normie como para bonus

acho que não preciso do multi bonus, faço tudo diretamente aqui no
proc bonus e se for preciso divido depois
senao tmb tenho a versao antiga a weird all

se eu usar o pipe_nmb na normie, vou ter que considerar
o normie como 1 e o bonus começa em 2, por isso, em vez de
-5 acho q é - 4? ac - 4 - all->append
ac = 5 , 4 args , é o normie e é suposto dar 1
ent
p = ac - 4 - app, ac = 5, p = 1 (normie)
ac = 6, p = 2 - app, p = 1 (normie) check
ac = 6, p = 2 - 0, p = 2 (multi) etc

append:
. file proc
. cmds norm/multi
Multi:
. file norm
. cmds multi
3 cenarios (a1m0, a1m1, a0m1)

-> files e flags primeiro
file 1: av[1] / heredoc
file 2: av[ac - 1] (ate mesmo no normie)
pipenmb: ac - 4 - all->append
append: 0 / 1
multi: 0 / 1

-> cmds depois
if (all->append == 1 && ac == 6)
	proc_cmds(av, 3, 4);
else
	proc_multi_cmds(ac, av);

proc all bonus
semelhante a proc all mas sem a parte dos cmds
e altero os files e flags, e serve para todos os bonus

struct so c flags, t_bflags
index_a
index_b
nmb
append
multi
heredoc (true false, 0/1)

tenho de introduzir variaveis de index a e b nas funcoes de
proc cmds, assim posso usar a mesma funcao no normie e no bonus, em vez de
funcoes diferentes so porque muda o av[2] para av[3];

multi pipes - 5 args ou mais
append - 5 args
*/

/////////////////////////////

/*
t_all	*weird_all(t_all *all, int ac, char **av)
{
	all->file1 = av[1];
	all->file2 = av[ac - 1];
	all->append = 0;
	all->pipe_nmb = 0;
	all->multi = 0;
	all->input = -1;
	if (av[1] == "here_doc")
	{
		all->append = 1;
		all->file1 = proc_delim(av[2]);
	}
	if (ac > 6)
	{
		all->multi = 1;
		all->pipe_nmb = ac - 5 - all->append;
	}
	if (all->append == 1 && ac == 6)
		all->cmds = proc_cmds(av, 3, 4); //unica situcação q se usa normie
	else
		all->cmds = proc_multi_cmds(ac, av, flag); //flag para ver se é append ou nao
	return(all);
}*/

/////////////////////////////

/*
t_all	*proc_heredoc(char **av, t_bflags *flags)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->file1 = proc_delim();
	all->file2 = ???; //depende?
	all->pipe_nmb = ???; //mandatory, é logo 0
	all->append = 1; //mandatory, é logo 0
	all->multi = ???; //mandatory, é logo 0
	all->input = -1; //usado mais à frente
	//all->cmds = proc_cmds(av);
	return(all);
}

t_all	*proc_all_bonus(char **av, t_bflags *flags)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (flags->heredoc == 1)
		all->file1 = proc_delim();
	else
		all->file1 = flags->ind_a;
	all->file2 = flags->ind_b;
	all->pipe_nmb = flags->nmb; //mandatory, é logo 0
	all->append = flags->append; //mandatory, é logo 0
	all->multi = flags->multi; //mandatory, é logo 0
	all->input = -1; //usado mais à frente
	//all->cmds = proc_cmds(av);
	return(all);
}
*/