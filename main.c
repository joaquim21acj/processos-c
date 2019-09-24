#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int i;
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
        pid_t pid_neto;
        //O código aqui dentro será executado no processo filho
        
        if ((pid_neto = fork()) < 0)
        {
            perror("fork");
            exit(1);
        }
        int neto;
        if (pid_neto == 0){
            neto = getpid();
            printf("Sou o processo %d neto\n", neto);
        }else{
            int filho = getpid();
            printf("Ola processo %d neto sou o processo %d filho\n", neto, filho);
        }
        
    }
    else
    {
        //O código neste trecho será executado no processo pai
        printf("Sou o processo %d pai, sejam bem vindos\n", getpid());
    }

    exit(0);
}