#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>


#define BUFFER_SIZE  43
#define READ_END      0
#define WRITE_END     1

    void confirma_msg(int sig) {
        
    if(sig == SIGTSTP) {
        //Control Z
        printf("\nSinal de usuario recebido: SIGTSTP (Signal Interrupt)\n");
        printf("Deseja enviar um sinal [s/n]? ");
        if(getchar() == 's'){
            
            pid_t pid;
            int fd[2];
            int escrevepipe = 10;
            int lepipe;
            
            //enviar pelo pipe
            
            if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe falhou");
    }
    pid= fork();
    
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
        printf("Filho leu: %d\n",lepipe*2);

        /* Fechar lado de leitura do pipe */
        close(fd[READ_END]);
    }
        
        }
        
    }else{
        if(sig == SIGINT){
            //Control C
        printf("\nSinal de usuario recebido: SIGINT (Signal Interrupt)\n");
        printf("Tem certeza que quer terminar [s/n]? ");
        if(getchar() == 's')
            exit(0);
        }
    }
}
int main() {
    if(signal(SIGINT, confirma_msg) == SIG_ERR){
        fprintf(stderr, "Nao foi possivel pegar o sinal");
    }
    if(signal(SIGTSTP, confirma_msg) == SIG_ERR){
        fprintf(stderr, "Nao foi possivel pegar o sinal");
    }
    printf("Bem-vindos ao programa signal\n");

    //mantém o código funcionando enquanto espera o sinal
    while(1)
        sleep(1);

    return 0;
}
