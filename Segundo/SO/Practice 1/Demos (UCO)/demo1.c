#include <sys/types.h> //Para estructura pid_t 
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>

int main(void) 
{
    pid_t pid;
    int status, childpid;
	int a= 5;
	int *p;
    p=&a;

    pid = fork(); 
    
    switch(pid)
    {
        case -1:
            perror("fork error");
            printf("errno value= %d\n", errno); exit(EXIT_FAILURE); 
            //return (-1);
            
        case 0: /* proceso hijo */
			a=10;
            printf("Proceso hijo %d; padre = %d, p=%p, a=%d \n", getpid(), getppid(),&a, *p); 
            exit(EXIT_SUCCESS);
            
        default: /* padre */
            printf("Proceso %d; padre = %d, p=%p , a=%d\n", getpid(), getppid(),&a, *p);
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
         
            exit(EXIT_SUCCESS); //return 0;
    }
}
