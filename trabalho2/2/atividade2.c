//Escreva um programa com 1 Pai e 2 Filhos
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid[2];

    for (int i = 0; i < 2; i++) {
        pid[i] = fork();

        if (pid[i] == 0) {
            printf("O pid do filho %d\n", i + 1);
            return 0;
        }
    }

    printf("Eu sou o Pai com pid %d\n");

    return 0;
}
