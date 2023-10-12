#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_THREADS 3

void* imprime_A(void *threadid) { //uma thread vai rodar essa função
    printf("A"); //impreme na tela
    sleep(1); //espera 1 segundo
    pthread_exit (NULL); //encerra
}

void* imprime_B(void *threadid) { //uma thread vai rodar essa função
    printf("B"); //impreme na tela
    sleep(1); //espera 1 segundo
    pthread_exit (NULL); //encerra
}

void* imprime_C(void *threadid) { //uma thread vai rodar essa função
    printf("C"); //impreme na tela
    sleep(1); //espera 1 segundo
    pthread_exit (NULL); //encerra
}

int main() {
    pthread_t thread[NUM_THREADS]; //cria array, cada elemento é um identificador de threand
    int status, i; //variaveis para argumentos das threads

    
    status = pthread_create (&thread[0], NULL, imprime_A, (void *) 0); //cria thread 1 e define sua função "impreme_A"
    status = pthread_create (&thread[1], NULL, imprime_B, (void *) 1); //cria thread 1 e define sua função "impreme_B"
    status = pthread_create (&thread[2], NULL, imprime_C, (void *) 2); //cria thread 1 e define sua função "impreme_C"
    
    for(i=0; i< NUM_THREADS; i++){  //checa erros na criação das threads
        if (status) { 
            perror ("pthread_create");
            exit (-1);
        }
        pthread_join(thread[i], NULL); //não permite que a função principal termine antes de todas as threads forem executadas
    }

    pthread_exit (NULL); //encerra
}
