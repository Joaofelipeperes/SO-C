#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#define SLEEP_TIME  2

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
    


    }
    else { /* Processo filho pid==0*/

    printf("EU P_B com o pid: %d, filho de %d\n" , getpid(), getppid());
    pid_t pid2;
    printf("Eu P_B criei P_C\n");
    pid2= fork();


    if(pid2 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }else{

        if(pid2 == 0) { /* Processo neto */
        printf("EU P_C com o pid: %d, pid interno %d, filho de %d\n" , getpid(), pid2, getppid());
    }
    }

    }

    return 0;
}