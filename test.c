#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*int main() {
    for (int i = 0; __environ[i] != NULL; i++) {
        if (__environ[i][0] == 'P' && __environ[i][1] == 'A'
            && __environ[i][2] == 'T' && __environ[i][3] == 'H')
        printf("%s\n", __environ[i]);
    }
    printf("%s\n", __environ[32]);
    char    *path;
    int i = 0;
    path = malloc(sizeof(__environ[32] - 4 + av[2]));
    while (__environ[32][i + 4] != '\0') {
        path[i] = __environ[32][i + 4];
        i++;
    }
    int j = 0;
    while (av[2][j] != '\0') {
        path[i] = av[2][j];
        i++;
        j++;
    }
}
//printar environ[32] == PATH
*/

/*int    f_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int main(int ac, char **av) {
    //char    *arr[] = {av[1], NULL};
    //execvp(av[1], arr);
    printf("----------\n");
    printf("environ[32]\n-> %s\n", __environ[32]);
    char    *path;
    char    *file;
    int i = 0;
    int sizep = f_strlen(__environ[32]) - 5;
    int sizef = f_strlen(__environ[32]) - 5 + f_strlen(av[1]);
    path = malloc(sizep + 1);
    file = malloc(sizef + 2);
    printf("sizep: %d, sizef: %d\n", sizep, sizef);
    while (__environ[32][i + 5] != '\0') {
        path[i] = __environ[32][i + 5];
        file[i] = __environ[32][i + 5];
        i++;
    }
    int j = 0;
    path[i] = '\0';
    file[i] = '/';
    i++;
    while (av[1][j] != '\0') {
        file[i] = av[1][j];
        i++;
        j++;
    }
    file[i] = '\0';
    printf("path\n-> %s\n", path);
    printf("file\n-> %s\n", file);
    char    *arr[] = {file, NULL};
    execve(path, arr, __environ);
}*/

/*int main(int ac, char **av) {
    char *arr[] = {av[1], NULL};
    printf("command is %s\n", av[1]);
    execve(av[1], arr, __environ);
    printf("error executing\n");
}
/usr/bin/ls*/

int main() {
    char *arr[] = {"/usr/bin/ls", "-1", NULL};
    execve("/usr/bin/ls", arr, __environ);
    printf("error executing\n");
}

char    **wch;
wch = malloc(3 * sizeof(char *));
wch[0] = "/usr/bin/which";
wch[1] = "cmd";
wch[2] = NULL;
execve("/usr/bin/which", wch, __environ);

//get cmd
while (av[2][i] != ' ') {i++;}
cmd = malloc(i * sizeof(char));
i = 0;
while (av[2][i] != ' ') {
    cmd[i] = av[2][i];
    i++;
}

//get flags
char    **cmd1;
cmd1 = ft_split(av[2], ' ');
wch[1] = cmd1[0];

char    **arr;
size = 2;
while (cmd1[i] != NULL) {i++;}
arr = malloc(size * sizeof(char *));
arr[0] = "wch";
arr[size - 1] = NULL;
while (size > 2) {arr[i] = cmd1;}
arr[size - 1] = NULL;

//here_doc
if (av[1] == "here_doc") {
    while {!= LIMITER} {
        read(0, mybuff, 1);
    }
}

//nao funciona com built in functions?
//certeza? vou assumir que nao
/*
-> which command, path
-> processar arguments (comando principal + flags)
-comecam por "-"? quase todos, talvez safe, mas nem todos
se nao for hifen nao estou a ver como distingo as fucking flags
resposta:
Encapsulation: Encourage users to encapsulate flags and arguments for a
specific command within quotation marks. For example, users might
input "ls -l" as a single argument, and you can then process it as
one command with the -l flag.
o argumento e so um, eu so tenho q processa-lo e encontrar um espaco dentro
split, f[0] comando, resto flags?
*/

/*
consegui isolar o path
environ[32] ou aqueles de cima
*/

/*
struct command, flag, next
atencao a usar flags nos comandos
se meter av[1] como nome do file e av[1] == "ls -l" vai dar erro
tenho q processar o nome ate aparecer so o comando principal e depois
o comando (serao considerados como mais av[]?)

In most Linux and Unix-like operating systems, the shell commands you commonly
use are located in the following directories:

    /bin: Essential system binaries
    /usr/bin: User-level command binaries
    /usr/local/bin: Locally installed software binaries



check de erros:
-> execve()
-> sss
-> pipes, fork
*/