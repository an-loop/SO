//etapa 1
//Escreva um programa com 1 Avo, 1 Pai e 1 Filho

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
            // processo filho
            printf("Eu sou o processo filho com PID %d\n", getpid());
        } else {
            // processo pai
            printf("Eu sou o processo pai com PID %d\n", getpid());
        }
    } else {
        // processo avo
        printf("Eu sou o processo avo com PID %d\n", getpid());
        sleep(10);
           

            printf("Eliminando processo Pai...\n");
            kill(pid1, SIGKILL);
            sleep(10);
            //processo pai e eliminado pela funcao kill
            //ha uma espera de 10s para que o pai seja morto e entao encontra-se o novo pai do processo filho
            } if (pid2 == 0) {
            printf("Sou o Filho: PID=%d e meu novo pai é PID=%d\n",getpid(),getppid());
            //Quando um processo morre, seus filhos sao adotados pelo processo init, que tem PID = 1
    }
    return 0;
}