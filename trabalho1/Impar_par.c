#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

int main(void) {
    int num;
    char buf[BUF_SIZE];
    char prompt[] = "Digite um número inteiro: ";
    char even[] = " é par.\n";
    char odd[] = " é ímpar.\n";
    
    // Escreve a mensagem de prompt na tela
    write(STDOUT_FILENO, prompt, strlen(prompt));
    
    // Lê o número digitado pelo usuário
    read(STDIN_FILENO, buf, BUF_SIZE);
    sscanf(buf, "%d", &num);
    
    // Converte o número para uma string
    int len = sprintf(buf, "%d", num);
    
    // Verifica se o número é par ou ímpar e escreve o resultado na tela
    if (num % 2 == 0) {
        write(STDOUT_FILENO, buf, len);
        write(STDOUT_FILENO, even, strlen(even));
    } else {
        write(STDOUT_FILENO, buf, len);
        write(STDOUT_FILENO, odd, strlen(odd));
    }

    // Sai do programa usando a chamada de sistema exit
    _exit(0);
    
    return 0;
}
