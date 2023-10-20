/*
 Programa: Uso de pipes em UNIX

 @adapted_from: Figures 3.21 & 3.22
 Operating System Concepts - Tenth Edition
 Silberschatz, Galvin, and Gagne

 @author: Prof. Dr. Aldo Diaz
          Instituto de Informatica - INF
          Universidade Federal de Goias - UFG
 Copyright Aldo Diaz - 2021
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE  43
#define READ_END      0
#define WRITE_END     1

int main(void) {
    pid_t pid;
    int fd[2];
    int escrevepipe = 10;
    int lepipe;

    /* Criar pipe */
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe falhou");
        return 1;
    }

    /* Criar processo filho */
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork falhou");
        return 1;
    }
    if (pid > 0) {  /* Processo pai */
        /* Fechar lado nao utilizado do pipe */
        close(fd[READ_END]);

        /* Escrever no pipe */
        printf("Pai: Escrever mensagem no pipe\n");
        write(fd[WRITE_END], &escrevepipe, sizeof(escrevepipe));

        /* Fechar lado de escritura do pipe */
        close(fd[WRITE_END]);
    }
    else { /* Processo filho */
        /* Fechar lado nao utilizado do pipe */
        close(fd[WRITE_END]);

        /* Ler pipe */
        read(fd[READ_END], &lepipe, sizeof(lepipe));
        printf("Filho leu: %d\n",lepipe +1);

        /* Fechar lado de leitura do pipe */
        close(fd[READ_END]);
    }

    return 0;
}