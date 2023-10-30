#include <unistd.h>
#include <stdio.h>

int main() {
    for (int i = 0; __environ[i] != NULL; i++) {
        if (__environ[i][0] == 'P' && __environ[i][1] == 'A'
            && __environ[i][2] == 'T' && __environ[i][3] == 'H')
        printf("%s\n", __environ[i]);
    }
    printf("%s\n", __environ[32]);
}

/*
consegui isolar o path
environ[32] ou aqueles de cima
*/