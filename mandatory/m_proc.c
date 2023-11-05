#include "pipex.h"

mudar arr[0] para which(arr[0]);
	->char **tmp {"/usr/bin/which", av[0], NULL};
	->pipe, fork
	->dup2(pipe[1], STDOUT_FILENO);
	->execve("/usr/bin/which", tmp, __environ);
	->wait(NULL);
	->free(tmp);
	->read char* from pipe

char	*read_pipe(int fd)
{
	char	*total;

	total;
	return(total)
}

void	exec_which(int *fd, char **tmp)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve("/usr/bin/which", tmp, __environ);
}

char	*proc_which(char *arr)
{
	char	*total;
	char	**tmp;
	int	**fd;
	int	pid;

	fd = malloc(2 * sizeof(int));
	pid = pipe(fd);
	tmp = malloc(3 * sizeof(char *));
	tmp[0] = "/usr/bin/which";
	tmp[1] = arr;
	tmp[2] = NULL;
	fork();
	if (pid == 0)
		exec_which(fd, tmp);
	wait(NULL);
	free(tmp);
	close(fd[1]);
	total = read_pipe(fd[0]); //
	free(fd);
	return(total);
}

t_cmd	*proc_cmds(char **av)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	new->arr = ft_split(av[1], ' ');
	new->arr = new_arr(new->arr); //acrescenta o NULL no fim
	new->arr[0] = proc_which(new->arr[0]);
	return(new);
}
/*
sabemos que é bonus quando o numero de args é maior q 4
ou por ter here_doc (ahh caga assim é com 4)

all->multi (pipe_nmb)
all->append (O_TRUNC), former flag
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
	all->pipe_nmb = 0; //mandatory, é logo 0
	all->append = 0; //mandatory, é logo 0
	all->multi = 0; //mandatory, é logo 0
	all->input = -1; //usado mais à frente
	all->cmds = proc_cmds(av);
	return(all);
	//which command av[2];
	//which command av[3];
	//cmds = proc_cmds(av);, cmds
	//all = proc_all(av, cmds); files
}

all->cmds = malloc(sizeof(t_cmd));
all->cmds->arr = ft_split(av[1], ' ');

execve leva (path, arr, environ)
-> path + array;
array = split só que o primeiro elemento leva o path atras

char	**arr;
cmds->arr = ft_split(av[1], ' ');
mudar arr[0] para which(arr[0]);
	->char **tmp {"/usr/bin/which", av[0], NULL};
	->pipe, fork
	->dup2(pipe[1], STDOUT_FILENO);
	->execve("/usr/bin/which", tmp, __environ);
	->wait(NULL);
	->free(tmp);
	->read char* from pipe
arr[last] = NULL;
	->len do char**
	->malloc new (len + 1);
	->new[i] = old[i], i++, new[last] = NULL;
	->free(char **arr), arr = new; free(char **new);
path = arr[0];

afinal nao sei se o "which" vai funcionar
porque tenho que mandar output para algum lado (pipe?)
criar pipe, exeec.which -> pipe, read from pipe -> char *buff

como ler ou fazer malloc sem saber tamanho?
realloc 1 a 1;
->if (!buff), buff = malloc(1);
->else if (buff) buff = realloc(+1);
->ret = read(1);
if (ret == 1), continue;
if (ret == 0), buff = realloc(+1), buff[last] = '\0', break;
será que preciso do \0 ou já vem?

char	*r_malloc(char *str)
{
	char	*new;
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	new = malloc((i + 1) * (sizeof(char)));
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	i++;
	new[i] = '\0';
	free(str);
	return(new);
}

char	**new_arr(char **arr)
{
	char	**new;
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	new = malloc((i + 1) * sizeof(char *));
	while (arr[i] != NULL)
	{
		new[i] = arr[i];
		i++;
	}
	new[i] = NULL;
	free(arr);
	return(new);
}

/*
typedef struct s_cmd {
	char	*cmd; // grep
	char	*wch; // /usr/bin
	char	*path; // /usr/bin/grep
	char	*input; //path to input file
	char	**flag;
	char	**arr;
	struct s_cmd	*next;
}	t_cmd;

tirar o input porque uso dup2 para isso
basicamente só deixar path e arr
cms->wch->path

typedef struct s_all {
	char	*file1;
	t_cmd	*cmds;
	char	*file2;
	int		input;
	int		pipe_nmb; //nº argv - 4 (if flag == 1, argv - 5)
	int		append; //0 para overwite, 1 para append mode
	int		multi; //0 para mandatory, 1 para multi pipes
}	t_all;
*/