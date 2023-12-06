/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:47 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/06 16:09:22 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
torna-se inutil se o LIMITER for decidido pelo enunciado e nao por mim
ya, sao 5 args, av[2] e o delimiter
*/

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

t_all	*proc_all_new(char **av)
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

t_all	*proc_central(t_all *all, int ac, char **av)
{
	//int	args;
	//args = 0;
	//while(av[args] != NULL)
		//args++;
	//if (args == 5)
		//proc_all(av);
	if (av[1] == "here_doc" && ac == 5) //append = 1; multi = 0
		all = proc_app(all);
	else if (av[1] != "here_doc" && ac > 5) //append = 0; multi = 1
		all = proc_mult(all);
	else if (av[1] == "here_doc" && ac > 5) //append = 1; multi = 1
		all = proc_app_mult(all);
	return(all);
}

/*
e se eu tentar modular os dois tipos de bonus
dois processamentos isolados q podem ser usados ambos ou sozinhos
em vez de fazer 3 ifs

multi pipes - 5 args ou mais
append - 5 args
*/


//--------------------------//--------------------------
//--------------------------//--------------------------
//--------------------------//--------------------------
//--------------------------//--------------------------
//--------------------------//--------------------------
//--------------------------//--------------------------

char	**new_arr(char **arr)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	while (arr[i] != NULL)
		i++;
	ft_printf("putting NULL on the end, initial size: %d\n", i); //tamanho 1
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

// --- fork which command e derivados --- //

char	*read_pipe(int fd)
{
	char	*total;
	int		err;

	err = 100;
	ft_printf("RRRRRRRRRRRR\nlets check reading errors, reading fd:%d\n", fd);
	total = malloc(100 * sizeof(char));
	while (err == 100)
	{
		err = read(fd, total, 100);
		ft_printf("err:%d, ", err);
		if (err == 0)
			break ;
		ft_printf("total:%s.\n", total);
	}
	total[err - 1] = '\0'; // - 1 pra retirar o standard \n no fim do output
	return(total);
}

/*
como dou mallocs novos constantes no total,
o ponteiro do read volta sempre ao inicio e so tem 1 char, que esta
sempre a ser substituido
e suposto eu saber o numero final ja antes?
ser suposto usar o which command ou assumir /usr/bin?
nao ha maneira de saber previamente sem ser assumir /usr/bin
unica maneira e assumir logo tipo char[100], nao e
otimizado mas olha
continua o mm problema? wtf??
se calhar a funcao read vai logo para o inicio.. ler 100 de cada vez?

leitura parece estar bem agora
*/

/*
mandei o output do execve c o "which" command para um pipe, aka,
file temporário, e agora para o poder usar como char * no meu codigo, tenho
que ler desse file, daí esta função
*/

void	exec_which(int pid, int *fd, char **tmp)
{
	close(fd[0]); //fecha fd[0]
	ft_printf("pid:%d, child process, making which command, fd[1]:%d\n", pid, fd[1]);
	dup2(fd[1], STDOUT_FILENO); //fecha fd[1] dup
	close(fd[1]); // fecha fd[1]
	if (execve("/usr/bin/which", tmp, ENV_VAR) == -1) {
		perror("error on execve\n");
	};
}

char	*proc_which(char *arr_zero)
{
	char	*total;
	char	**tmp;
	int		*fd;
	int		pid;

	fd = malloc(2 * sizeof(int));
	ft_printf("================\nputting PATH on first element\n");
	ft_printf("initial arr[0]:%s.\n", arr_zero);
	pipe(fd);
	ft_printf("fd[0]: %d, fd[1]: %d\n", fd[0], fd[1]);
	tmp = malloc(3 * sizeof(char *));
	tmp[0] = "/usr/bin/which";
	tmp[1] = arr_zero;
	tmp[2] = NULL;
	ft_printf("tmp[0]:%s.\ntmp[1]:%s.\ntmp[2]:%s.\n", tmp[0], tmp[1], tmp[2]);
	ft_printf("will fork\n");
	pid = fork();
	if (pid == -1)
		perror("error on fork\n");
	if (pid == 0)
		exec_which(pid, fd, tmp);
	wait(NULL);
	printf("parent pid: %d, fd[0]: %d\n", pid, fd[0]);
	free(tmp); //melhorar este free, char ** nao e char *
	close(fd[1]);
	total = read_pipe(fd[0]);
	close(fd[0]); //ou aqui ou no read_pipe p poupar linhas
	free(fd);
	ft_printf("final arr[0]:%s.\n", total);
	return(total);
}

// --- criar estrutura all e derivados --- //

void	print_arr(char **arr) {
	int	i = 0;
	while (arr[i] != NULL)
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
	t_cmd	*begin;

	new = malloc(sizeof(t_cmd));
	ft_printf("start cmds\n");
	ft_printf("av[2]: %s\n", av[2]);
	new->arr = ft_split(av[2], ' '); //primeiro set de comandos na char **
	print_arr(new->arr);
	new->arr = new_arr(new->arr); //acrescenta o NULL no fim
	print_arr(new->arr);
	new->arr[0] = proc_which(new->arr[0]); //muda o primeiro elemento para PATH
	print_arr(new->arr);
	ft_printf("--- FIRST PROCC ---\n");
	begin = new;
	new->next = malloc(sizeof(t_cmd)); //new atualmente == NULL, por isso, dar novo malloc
	new = new->next; //char ** = char ** next
	new->arr = ft_split(av[3], ' '); //segundo set de comandos na char **
	new->arr = new_arr(new->arr); //acrescenta o NULL no fim
	new->arr[0] = proc_which(new->arr[0]); //muda o primeiro elemento para PATH
	ft_printf("--- SECOND PROCC ---\n");
	new->next = NULL;
	print_arr(new->arr);
	//new = begin;
	return(begin);
}
/*
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
	//ft_printf("creating all\n");
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
