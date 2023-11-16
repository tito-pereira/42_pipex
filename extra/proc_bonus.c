#include "pipex_bonus.h"

char	*read_term()
{
	char	*new;
	char	*tmp;
	int		i;
	int		err;

	i = 0;
	err = 1;
	new = malloc(sizeof(char));
	new = '\0';
	tmp = malloc(2 * sizeof(char));
	tmp[1] = '\0';
	while(i++ && err != 0)
	{
		err = read(0, tmp, 1);
		if (err == 0)
		{
			free(tmp);
			return(new);
		}
		//sera q adiciono err = -1 e um erro?
		tmp[err] = '\0';
		new = fill_chest(tmp, new);
		if(new[i] == 'M')
		{
			if(new[i - 1] == 'I')
			{
				if(new[i - 2] == 'L')
				{
					free(tmp);
					break ;
				}
			}
		}
	}
	return(new);
}

char	*fill_chest(char *tmp, char *old)
{
	char	*new;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(old);
	new = malloc((len + 2) * sizeof(char));
	while (old[i] != '\0')
	{
		new[i] = old[i];
		i++;
	}
	new[len] = tmp[0];
	new[len + 1] = '\0';
	free(old); //acho que é preciso não? testar depois
	return(new);
}

/*
função usada para ler do terminal 
new

eu nao posso ler varias vezes para o mesmo sitio
aquilo nao acumula o buffer, apenas o substitui

acrescentar as condições de fim de leitura quando a funcao read()
retorna 0
fazer a função de_malloc, que retira o espaço em branco
*/

/*
faco if sucessivos em vez de um só if ou while porque, no inicio,
so vou ter malloc de 1 e nao consigo aceder a 3 posicoes de pointer se só
existe uma, vai dar erro de compilação
size of 1, se eu tentar aceder a 3 posições vai dar logo erro
*/

t_all	*proc_all(char **av)
{
	t_all	*all;
	int	c;

	c = 0;
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
	all->cmds = proc_cmds_bonus(av);
	return(all);
}

/*
o proc cmds bonus vai precisar de um while loop qq
nao posso usar o proc commands normal, vou precisar do proc cmds bonus
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
usar só no bonus
*/