#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <errno.h>

/*Pruebe por ejemplo: “./a.out tar -cf prueba.tar file1 file2 fileN” donde file1 hasta fileN son ficheros que desea comprimir en el fichero prueba.tar
 Pruébelo también sin usar nada en la linea de argumentos.
 Por ultimo pruébelo usando un "file1" que no exista.
 */
int main(int argc, char **argv) 
{
    pid_t pid;
    int status, childpid;
    
    pid = fork(); 
    switch(pid) 
    {
        case -1: /* error del fork() */ 
            perror("fork error");
            printf("errno value= %d\n", errno); 
            exit(-1);
        case 0: /* proceso hijo */
            printf("Soy el hijo y mi PID es:%d\n",getpid()); 
            if (execvp(argv[1], &argv[1]) < 0)
            {
                perror("exec");
                printf("errno value= %d\n", errno);
                exit(EXIT_FAILURE); 
            }
        default: /* padre */
            printf("Valor del PID recibido por el padre en el fork, coincide con el PID del hijo:%d\n",pid); 
            childpid=wait(&status);
            if(childpid>0) 
            {
                if (WIFEXITED(status)) {
                     printf("child %d exited, status=%d\n",childpid, WEXITSTATUS(status));
                       
                } 
                else if (WIFSIGNALED(status)) 
                {
                    printf("child %d killed (signal %d)\n", childpid, WTERMSIG(status));
                       
                } else if (WIFSTOPPED(status)) 
                {
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
