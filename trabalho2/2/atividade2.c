//criar um processo pai e dois filhos

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        printf("Filho 1: Meu PID é %d. O PID do meu pai é %d.\n", getpid(), getppid());
        exit(0);
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("Filho 2: Meu PID é %d. O PID do meu pai é %d.\n", getpid(), getppid());
        exit(0);
    }

    printf("Pai: Meu PID é %d. Os PIDs dos meus filhos são %d e %d.\n", getpid(), pid1, pid2);

    return 0;
}

