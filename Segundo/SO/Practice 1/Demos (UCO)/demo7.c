#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*Pruebe por ejemplo: “./a.out tar -cf prueba.tar file1 file2 fileN” donde file1 hasta fileN son ficheros que desea comprimir en el fichero prueba.tar*/

int main(int argc, char **argv) 
{
    pid_t pid; 
    int status, childpid;
    
    pid = fork();
    switch(pid) {
        case -1: /* error del fork() */ 
			perror("fork error");
            printf("errno value= %d\n", errno); 
			exit(EXIT_FAILURE);
        case 0: /* proceso hijo */
            if ( execvp(argv[1], &argv[1]) < 0 ) //Exec devuelve -1 en caso de error 
            {
                perror("exec");
                printf("errno value= %d\n", errno); exit(EXIT_FAILURE);
            }
        default: /* padre */
            printf("padre con pid: %ld\n", (long)getpid()); childpid=wait(&status);
            if(childpid>0)
            {
                if (WIFEXITED(status)) {
                    printf("child %d exited, status=%d\n",childpid, WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("child %d killed (signal %d)\n", childpid, WTERMSIG(status));
                } else if (WIFSTOPPED(status)) {
                    printf("child %d stopped (signal %d)\n", childpid, WSTOPSIG(status));
                } 
            }
            if (childpid==-1 && errno==ECHILD) {
				printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n"); 
                exit(EXIT_FAILURE);
			}
            else {
            	printf("No hay más hijos que esperar\n");    
            } 
    }
}
