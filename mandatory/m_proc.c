#include "pipex.h"

t_cmd	*proc_cmds(char **av)
{
	ez;
}
/*
sabemos que é bonus quando o numero de args é maior q 4
ou por ter here_doc (ahh caga assim é com 4)

all->multi
all->append
*/

t_all	*proc_all(char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (av[1] == "here_doc")
	{
		all->flag = 1;
		all->bonus = 1;
		read(0); //provavelmente função à parte
	}
	all->file1 = av[1];
	all->file2 = av[4];
	all->pipe_nmb = 0;
	all->flag = 0;
	all->bonus = 0;
	all->input = -1;
	all->cmds = proc_cmds(av);
	return(all);
	//which command av[2];
	//which command av[3];
	//cmds = proc_cmds(av);, cmds
	//all = proc_all(av, cmds); files
	/*in = open(av[1], O_RDONLY);
	if (in == -1)
		ft_printf("Error with input file\n");
	posso usar o mesmo main para tudo, incluindo o
	all = proc_all e o 
	while (pipe_nmb)
	e apenas mudo o valor do pipe_nmb e o processamento
	do av[1] dentro do proc_all*/
}

/*
typedef struct s_cmd {
	char	*cmd;
	char	*wch;
	char	*path; //path to cmd
	char	*input; //path to input file
	char	**flag;
	char	**arr;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_all {
	char	*file1;
	t_cmd	*cmds;
	char	*file2;
	int		input;
	int		pipe_nmb; //nº argv - 4 (if flag == 1, argv - 5)
	int		flag; //0 para overwite, 1 para append
	int		bonus; //0 para mandatory, 1 para bonus
}	t_all;
*/