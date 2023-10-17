//atividade3
//Escreva um programa com 1 Avo, 1 Pai e 1 Filho, elimine o processo Pai e veja quem sera o novo pai do processo Filho;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>


int main() {
    pid_t pid, pid2;

    pid = fork();
    //pid pai criando o filho

    if (pid == 0) {
        printf("Pai: PID=%d\n", getpid());
        exit(0);
        // se o pid for igual a 0, entao ele e o processo filho e mostrara seu pid
    } else if (pid > 0) {
        // se o pid for maior que 0, entao e o processo pai
        pid2 = fork();
        //processo pai se tornando avo 
        if (pid2 == 0) 
          {
            printf("Filho: PID=%d\n", getpid());
            exit(0);

        } else if (pid2 > 0) {
            printf("Avo: PID=%d\n ", getpid());
            sleep(10);
            //apos a duplicacao, encontra-se o processo pai e avo
            //ha uma espera para a finalizacao do processo

            printf("Eliminando processo Pai...\n");
            kill(pid2, SIGKILL);
            sleep(10);
            //processo pai e eliminado pela funcao kill
            //ha uma espera de 10s para que o pai seja morto e entao encontra-se o novo pai do processo filho
            printf("Novo pai do processo Filho e o processo Avo.\n");
            //Quando um processo morre, seus filhos sao adotados pelo processo init, que tem PID = 1

        } else {
            perror("fork");
            exit(1);
        }
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}


