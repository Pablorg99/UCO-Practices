#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h>


int main(void) 
{
    pid_t hijo_pid; 
    int status, childpid;
    
    hijo_pid= fork(); 
    
    if (hijo_pid == -1) 
    {
        perror("fork error");
        printf("errno value= %d\n", errno); 
        exit(-1);
    }
    else if (hijo_pid == 0) 
    {
        printf("hijo con pid: %ld\n", (long)getpid());
        exit(EXIT_SUCCESS); //Necesaria la librería <stdlib.h> 
    }
    else /* padre */ 
    {
        printf("padre con pid: %ld\n", (long)getpid()); 
        childpid=wait(&status);
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
		printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal\n");
              exit(EXIT_FAILURE);
	}
        else {              
                printf("No hay más hijos que esperar\n");
        }
        exit(EXIT_SUCCESS); //return 0; 
    }
}
