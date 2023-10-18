#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define LIMITE_PROCESSO 100000000
#define LIMITE_THREAD 100000000

void* funcao_thread(void* arg){
    pthread_exit(NULL);
}

int main()
{

    //Processos

    printf("Teste do limite de criacao dos Processos: \n");

    int i, pid;

    for(i=1; i <= LIMITE_PROCESSO; i++){
        pid = fork();
        if (pid < 0){
            printf("Limte de Processos excedido: %d\n", i - 1);
            break;
        }
        if(pid == 0){
            exit(0);
        }
    }

    if(pid > 0){
        for(int j=0; j < i; j++){
            wait(NULL);
        } 
        printf("Teste processos concluido\n");
    }


    //Threads


    printf("\nTeste do limite de criacao de Threads: \n");

    pthread_t thread;

    for(int i = 1; i <= LIMITE_THREAD; i++){
        if(pthread_create(&thread, NULL, funcao_thread, NULL) != 0){
            printf("Limite de Threads excedido: %d\n", i+1);
            break;
        }
    }

    if(i == LIMITE_THREAD + 1){
        printf("Teste threads concluido\n");
    }

    return 0;
}