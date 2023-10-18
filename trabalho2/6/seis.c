#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sort(int* vet, int n) { //codigo de ordenacao por ordem crescente
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (vet[j] > vet[j+1]) {
                int temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}

int main() {

    //cria um vetor de 100 posicoes
    int vet[100];

    //adiciona valor a cada posicao do vetor
    for (int i = 0; i < 100; i++) {
        vet[i] = rand() % 100;
    }

    //exibe o vetor 100 antes da criacao do Filho 
    printf("Valor do Pai antes do Filho ordenar: \n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n\n");

    //chama comando fork para copiar processo Pai
    int pid = fork();


    if (pid == 0) {

        //Processo Filho ordena o vetor 100
        sort(vet, 100);

        printf("Valor do vetor ordenado pelo Filho depois do fork: \n");
        for (int i = 0; i < 100; i++) {
            printf("%d ", vet[i]);
        }
        printf("\n\n");

        //finalizacao do processo Filho
        _exit(0);
    } else if (pid > 0) {

        //processo Pai espera a finalizacao do processo Filho
        waitpid(NULL);


        //processo Pai imprime na tela o vetor 100
        printf("Valor do vetor do Pai depois do Filho ordenar: \n");
        for (int i = 0; i < 100; i++) {
            printf("%d ", vet[i]);
        }
        printf("\n");
    }


    //os processos Pai e Filho terao vetores diferentes, pois apos a criacao do Filho
    //ele age de forma independente, possuindo seu proprio espaço de memoria.
    //ou seja, qualquer alteracao realizada no vetor do filho nao influenciara no processo Pai


    return 0;
}
