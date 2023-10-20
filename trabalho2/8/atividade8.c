//Crie um programa (ou altere um dos anteriores) demodo a lhe permitir comparar o desempenho para arealização da(s) tarefa(s) do programa
// através do uso deprimitivas fork e através de threads (calcule a média detempo de 20 simulações

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>

#define NUM_SIMULATIONS 20

void* funcaot(void* threadid) { 
// uma thread vai rodar essa funcao
    wait(NULL);
}

int main() {
    pid_t pid;
    int status;
    pthread_t thread;
    clock_t start_time, end_time;
    double total_time_fork = 0.0, total_time_thread = 0.0;

    // Simulacao dos Forks
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        start_time = clock();
        pid = fork();
        if (pid == 0) {
            // Processo filho
            exit(0);
        } else if (pid > 0) {
            // Processo pai
            wait(&status);
            end_time = clock();
            total_time_fork += ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
        } else {
            printf("Erro ao criar o processo filho\n");
            exit(1);
        }
    }

    // Simulacao das Threads
    
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        start_time = clock();
        pthread_create(&thread, NULL, funcaot, NULL);
        pthread_join(thread, NULL);
        end_time = clock();
        total_time_thread += ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
}

    printf("Tempo medio por Processos: %f por segundos\n", total_time_fork / NUM_SIMULATIONS);
    printf("Tempo medio por Threads: %f por segundos\n", total_time_thread / NUM_SIMULATIONS);

    return 0;
}

