#include "pipex.h"

/*
errors:
1 - pipe in first command
2 - fork in first command

{
    free(p1);
    free_all(all);
}

man_error(1, p1, all);
pipe e fork em si não é suposto darem erros
só dão erro se houver leaks de memoria e a quantidade de
process IDs ou file descriptors exceder o limite
*/