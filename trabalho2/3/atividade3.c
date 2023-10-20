//atividade3
//Escreva um programa com 1 Avo, 1 Pai e 1 Filho, elimine o processo Pai e veja quem sera o novo pai do processo Filho;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>


int main() {
    pid_t pid1, pid2;

    pid = fork();
    //processo avo criando o processo pai

    if (pid1 == 0) {
        printf("Pai: PID=%d\n", getpid());
        exit(0);
        // processo pai ira mostrar seu pid atraves da funcao getpid()
        } else if (pid1 > 0) {
            
         pid2 = fork();
        //criacao do processo filho
        if (pid2 == 0) 
          {
            printf("Sou o Filho: PID=%d e meu pai é %d\n", getpid(),getppid());
            exit(0);

        } else if (pid2 > 0) {
            printf("Avo: PID=%d\n ", getpid());
            sleep(10);
            //apos a duplicacao, encontra-se o processo pai e avo
            //ha uma espera para a finalizacao do processo

            printf("Eliminando processo Pai...\n");
            kill(pid1, SIGKILL);
            sleep(10);
            //processo pai e eliminado pela funcao kill
            //ha uma espera de 10s para que o pai seja morto e entao encontra-se o novo pai do processo filho
            } if (pid2 == 0) {
            printf("Sou o Filho: PID=%d e meu novo pai é PID=%d\n",getpid(),getppid());
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


