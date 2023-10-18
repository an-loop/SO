#include <stdio.h>
#include <pthread.h>


#define NUM_THREADS 3
volatile int turn = 0;


void* imprime_A(void* threadid) { // uma thread vai rodar essa função
    while(1) { //loop infinito
        while(turn == 0){ //loop q continua quando turn for igual a 0. Faz a thread esperar sua vez para printar A
        printf("A"); // imprime A na tela
        turn = 1; // muda o valor, passa para proxima thread
        }
        
    }
}

void* imprime_B(void* threadid) { // uma thread vai rodar essa função
    while(1) { //loop infinito
        while(turn == 1){ //loop q continua quando turn for igual a 1. Faz a thread esperar sua vez para printar B
        printf("B"); // imprime B na tela
        turn = 2; // muda o valor, passa para proxima thread
        }
        
    }
}

void* imprime_C(void* threadid) { // uma thread vai rodar essa função
    while(1) { //loop infinito
        while(turn == 2){ //loop q continua quando turn for igual a 2. Faz a thread esperar sua vez para printar C
        printf("C\n"); // imprime C na tela
        turn = 0; // muda o valor, passa para proxima thread
        }
        
    }
}

int main() {
    pthread_t thread[NUM_THREADS]; //cria array, cada elemento é um identificador da thread

    
    pthread_create (&thread[0], NULL, imprime_A, NULL); //cria thread 1 e define sua função "impreme_A"
    pthread_create (&thread[1], NULL, imprime_B, NULL); //cria thread 2 e define sua função "impreme_B"
    pthread_create (&thread[2], NULL, imprime_C, NULL); //cria thread 3 e define sua função "impreme_C"
    
    for(int i=0; i< NUM_THREADS; i++){ 
        pthread_join(thread[i], NULL); //não permite que a função principal termine antes de todas as threads forem executadas
    }

    return 0;
}
