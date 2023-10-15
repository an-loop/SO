etapa 1
//Escreva um programa com 1 Avo, 1 Pai e 1 Filho

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 == 0) {
        // duplicacao de pid1
        pid2 = fork();
        if (pid2 == 0) {
            // processo avo
            printf("Eu sou o processo avo com PID %d\n", getpid());
        } else {
            // processo filho
            printf("Eu sou o processo filho com PID %d\n", getpid());
        }
    } else {
        // processo pai
        printf("Eu sou o processo pai com PID %d\n", getpid());
    }
    return 0;
}