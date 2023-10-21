#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>


int main() {
    printf("EU P_A com o pid: %d, filho de %d\n" , getpid(), getppid());
    pid_t pid;
    printf("Eu P_A criei P_B\n");
    pid = fork();
    if(pid < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid > 0) { /* Processo pai */
    
    wait(NULL);

    printf("Eu P_A aguardei P_B terminar\n");
    printf("Eu P_A executei: ps\n");
    execlp("ps", "ps", NULL);

    }
    else { /* Processo filho pid==0*/

    printf("EU P_B com o pid: %d, pid interno %d, filho de %d\n" , getpid(), pid, getppid());
    pid_t pid2;
    printf("Eu P_B criei P_C\n");
    pid2= fork();

    if(pid2 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }else{

        if(pid2 == 0) { /* Processo neto */
        printf("EU P_C com o pid: %d, pid interno %d, filho de %d\n" , getpid(), pid2, getppid());
        printf("Eu P_C executei ps\n");
        execlp("ps", "ps", NULL);
    }else{
        if(pid2 >0 ){ //processo pai (B);
        wait(NULL);
    printf("Eu P_B aguardei P_C Terminar\n");
    printf("Eu P_B executei ps\n");
    execlp("ps", "ps", NULL);
    }
    }
    }

    }

    return 0;
}