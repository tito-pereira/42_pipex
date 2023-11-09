#include "pipex_bonus.h"

char	*read_term()
{
	char	*new;
	int	i;
	int	err;

	new = malloc(sizeof(char));
	err = 1;
	i = 0;
	new = '\0';
	while(i++ && err != 0)
	{
		err = read(0, new, 1);
		if(new[i] == 'M')
		{
			if(new[i - 1] == 'I')
			{
				if(new[i - 2] == 'L')
					break ;
			}
		}
		if (err == 1)
			new = r_malloc(new);
	}
	return(new);
}
/*
faco if sucessivos em vez de um só if ou while porque, no inicio,
so vou ter malloc de 1 e nao consigo aceder a 3 posicoes de pointer se só
existe uma, vai dar erro de compilação
*/

t_all	*proc_all(char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (av[1] == "here_doc")
	{
		all->append = 1;
		av[1] = read_term();
	}
	else
		all->append = 0;
	all->file1 = av[1];
	while (av[c] != NULL)
		c++;
	if (c == 5)
	{
		all->pipe_nmb = 0;
		all->multi = 0;
		all->file2 = av[4];
	}
	else
	{
		all->pipe_nmb = c - 5; //menos qq coisa, c - 5 p exemplo
		all->multi = 1;
		all->file2 = av[c];
	}
	all->input = -1; //usado mais à frente
	all->cmds = proc_cmds(av);
	return(all);
}

/*
o proc cmds bonus vai precisar de um while loop qq
*/

t_all	*proc_central(char **av)
{
	int	c;

	c = 0;
	while(av[c] != NULL)
		c++;
	if (c == 4)
		return(m_proc(av));
	return(proc_bonus(av));
}

/*
na main bonus, em vez de mandar para uma proc, mando para esta central
*/