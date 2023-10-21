#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>


int main() {

    printf("Systemd  pid: %d\n", getpid());

    pid_t pid;
    pid= fork();

    if(pid < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid == 0) { /* Processo filho  Pyton*/
        printf("Python pid: %d filho de %d\n", getpid(), getppid());
    }
    else { /* Processo pai  systemd*/
    pid_t pid2;

    pid2=fork();

    if(pid2 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid2 == 0) { /* Processo filho  logind*/
        printf("Lodind pid: %d filho de %d\n", getpid(), getppid());

        pid_t pid6;
        pid6=fork();

        if(pid6 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid6 == 0) { /* Processo filho  Bash*/
        printf("Bash pid: %d filho de %d\n", getpid(), getppid());

        pid_t pid7;
        pid7=fork();

        if(pid7 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid7 == 0) { /* Processo filho  PS*/
        printf("PS pid: %d filho de %d\n", getpid(), getppid());
    }
    else { /* Processo pai  Bash*/

    pid_t pid8;
    pid8=fork();

    if(pid8 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid8 == 0) { /* Processo filho  Vim*/
        printf("Vim pid: %d filho de %d\n", getpid(), getppid());
    }
    else { /* Processo pai  Bash*/

    
    }
    
    }
    }
    else { /* Processo pai  Loginxd*/


    }

    }
    else { /* Processo pai  systemd*/
    pid_t pid3;

    pid3=fork();

    if(pid3 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid3 == 0) { /* Processo filho  Sshd1*/
        printf("SSHD1 pid: %d filho de %d\n", getpid(), getppid());

        pid_t pid4;
        pid4= fork();

        if(pid4 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid4 == 0) { /* Processo filho  Sshd2*/
        printf("SSHD2 pid: %d filho de %d\n", getpid(), getppid());

        pid_t pid5;
        pid5= fork();

        if(pid5 < 0) {
        fprintf(stderr, "Fork falhou\n");
        return 1;
    }
    if(pid5 == 0) { /* Processo filho  TCSH*/
        printf("TCSH pid: %d filho de %d\n", getpid(), getppid());
    }
    else { /* Processo pai  SSHD2*/

    
    }
    }
    else { /* Processo pai  SSHD1*/

    
    }

    }
    else { /* Processo pai  systemd*/

    
    }
    
    }
    }

    return 0;
}

