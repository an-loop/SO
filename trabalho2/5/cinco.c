#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    //criando a variavel com o pid do pai
    int pid = 1;


    //pid do pai antes de executar o comando fork 
    printf("PID Pai: %d\n", pid);

    //comando fork sendo executado (criacao de um filho)
    int ret = fork();


    //se o numero de fork for igual a 0, é o processo filho
    if (ret == 0) {

        //alterando o valor do pid 
        pid = 5;

        //valor do pid do filho antes do comando exit
        printf("PID do Filho: %d\n", pid);

        //comando exit ()
        _exit(0);


    } else if (ret > 0) { //se o numero do fork for maior que 0, é o processo pai

        // Processo pai espera o processo filho finalizar
        waitpid(NULL);

        //valor final do pid do pai 
        printf("Valor final do Pai: %d\n", pid);
    }
    return 0;
}




    //O valor inicial do PAI é 1 e o final continua o mesmo valor independentemente da alteração feita pelo Filho
    //Isso acontece pois, o comando fork cria uma copia exata do processo Pai, porém apos criada a copia (Filho)
    //o processo Pai age isolado do processo filho
    //Isso é, o Filho tem sua propria copia do valor e qualquer alteracao feita nele não afetará o valor do Pai.

