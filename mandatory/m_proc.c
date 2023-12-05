#include "pipex.h"

// --- suportes --- //

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
/*
destroi o malloc e faz um malloc novo c mais 1 byte em branco
(para poder ler mais 1 byte)
*/

char	**new_arr(char **arr)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	while (arr[i] != NULL)
		i++;
	ft_printf("making new arr\ni: %d\n", i); //tamanho 1
	new = malloc((i + 1) * sizeof(char *)); //malloc 2
	j = 0;
	while (j < i) //while 0<1 [0]
	{
		new[j] = arr[j];
		j++;
	}
	new[i] = NULL; //new[0] = ls; new[1] = NULL;
	free(arr);
	return(new);
}
/*
acrescenta em elemento NULL no fim do char **array
(para ser usado na funcao execve)
vamos assumir que esta bem
*/

char	*sub_malloc(char *total)
{
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(total);
	new = malloc(len * sizeof(char));
	i = 0;
	while (i <= len)
	{
		new[i] = total[i];
		i--;
	}
	new[len] = '\0';
	return (new);
}

// --- fork which command e derivados --- //

char	*read_pipe(int fd)
{
	char	*total;
	int	err;
	int	i;

	err = 1;
	i = 0;
	total = malloc(2 * sizeof(char));
	total[1] = '\0';
	while (i++ && err != 0)
	{
		err = read(fd, total, 1);
		if (err == 1)
			total = r_malloc(total);
		else if (err == 0)
		{
			total = sub_malloc(total);
			break ;
		}
	}
	return(total);
}

/*
mandei o output do execve c o "which" command para um pipe, aka,
file temporário, e agora para o poder usar como char * no meu codigo, tenho
que ler desse file, daí esta função
*/

void	exec_which(int *fd, char **tmp)
{
	ft_printf("child process, making which command\n");
	dup2(fd[1], STDOUT_FILENO); //fecha fd[1] dup
	close(fd[0]); //fecha fd[0]
	close(fd[1]); // fecha fd[1]
	//ft_printf("TTTTT\n");
	execve("/usr/bin/which", tmp, __environ);
}

char	*proc_which(char *arr_zero)
{
	char	*total;
	char	**tmp;
	int		*fd;
	int		pid;

	fd = malloc(2 * sizeof(int));
	ft_printf("im inside proc_which\n");
	//ft_printf("arr[0]: %s\n", arr_zero);
	total = NULL;
	pid = pipe(fd);
	tmp = malloc(3 * sizeof(char *));
	tmp[0] = "/usr/bin/which";
	tmp[1] = arr_zero;
	tmp[2] = NULL;
	ft_printf("tmp[0]: %s\ntmp[1]: %s\ntmp[2]: %s\n", tmp[0], tmp[1], tmp[2]);
	ft_printf("will fork\n");
	fork();
	if (pid == 0)
		exec_which(fd, tmp);
	else
	{
		wait(NULL);
		ft_printf("waited\n");
		free(tmp); //melhorar este free, char ** nao e char *
		close(fd[1]);
		total = read_pipe(fd[0]);
		close(fd[0]); //ou aqui ou no read_pipe p poupar linhas
		free(fd);
	}
	return(total);
}

// --- criar estrutura all e derivados --- //

void	print_arr(char **arr) {
	int	i = 0;
	while (arr[i])
		i++;
	ft_printf("---------------\nthe array has %d elements\n", i);
	int	j = 0;
	while (j <= i) {
		ft_printf("arr[%d]:%s\n", j, arr[j]);
		j++;
	}
}
//só para teste, apagar depois

t_cmd	*proc_cmds(char **av)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	ft_printf("start cmds\n");
	ft_printf("av[2]: %s\n", av[2]);
	new->arr = ft_split(av[2], ' '); //primeiro set de comandos na char **
	print_arr(new->arr);
	new->arr = new_arr(new->arr); //acrescenta o NULL no fim
	print_arr(new->arr);
	new->arr[0] = proc_which(new->arr[0]); //muda o primeiro elemento para PATH
	print_arr(new->arr);
	new = new->next; //char ** = char ** next
	new = malloc(sizeof(t_cmd)); //new atualmente == NULL, por isso, dar novo malloc
	new->arr = ft_split(av[3], ' '); //segundo set de comandos na char **
	new->arr = new_arr(new->arr); //acrescenta o NULL no fim
	new->arr[0] = proc_which(new->arr[0]); //muda o primeiro elemento para PATH
	new->next = NULL;
	return(new);
}
/*
pra ja detetei que existe um erro qq na funcao new_arr, ainda n sei qual
(vou so assumir q esta bem)

erro na proc_which

so fazemos av[2] e [3] porque este é a parte mandatory, sem bonus,
ja sei de antemao que só recebo 4 args
eu tou a acrescentar NULL no fim, boa
mas tou so a alterar o arr[0] para o seu path
e nao estou a repeti-lo
devia ser:
arr[0] = command path (which command)
arr[1] = igual (repeat)
acho que vou ter que duplicar primeiro o arr[0] e so depois modificar
*/

t_all	*proc_all(char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	ft_printf("creating all\n");
	all->file1 = av[1];
	all->file2 = av[4];
	ft_printf("file1: %s\nfile2: %s;\n", all->file1, all->file2);
	all->pipe_nmb = 0; //mandatory, é logo 0
	all->append = 0; //mandatory, é logo 0
	all->multi = 0; //mandatory, é logo 0
	all->input = -1; //usado mais à frente
	all->cmds = proc_cmds(av);
	return(all);
}

// --- rascunhos ---

/*
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
*/

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