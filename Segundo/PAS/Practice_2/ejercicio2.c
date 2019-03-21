#include <stdio.h>
#include <stdlib.h> 
/* For pipe(), fork() etc */
#include <unistd.h> 
#include <sys/wait.h>
/* Use strcat() and strtok() */
#include <string.h>

char *getNumbersKind(char *buffer);
char *askNumbers();

int main(void)
{
	pid_t pid;
	int status;
	int fileDesPipe1[2];
	int fileDesPipe2[2];
	const int BSIZE = 100;
	char buffer[BSIZE];
	char *writer;
	ssize_t nbytes;

	/* Pipe creations */
	if((status = pipe(fileDesPipe1)) == -1) {
		perror("Could not create pipe 1");
		exit(EXIT_FAILURE);
	}
	if((status = pipe(fileDesPipe2)) == -1) {
		perror("Could not create pipe 2");
		exit(EXIT_FAILURE);
	}

	switch (fork())
	{
		case -1:
			perror("Could not create child process");
			break;

		case 0: /* CHILD */
			/*------------------------READING--------------------------------*/
			/* We are reading, so we do not need to write*/
			if(close(fileDesPipe1[1]) == -1) {
				perror("Close error");
				exit(EXIT_FAILURE);
			}
			/* Reading process (blocking call) */
			nbytes = read(fileDesPipe1[0], buffer, BSIZE);
			if(nbytes == -1) {
				perror("Error when reading pipe");
				exit(EXIT_FAILURE);
			}
			else if (nbytes == 0) printf("CHILD: Father closed the pipe");
			else printf("CHILD: I have read %s from pipe 1\n", buffer);
			/* Pipe closing */
			if(close(fileDesPipe1[0])) {
				perror("Close error");
				exit(EXIT_FAILURE);
			}
			else printf("CHILD: Closed pipe 1\n");
			/*-------------------------WRITTING------------------------------*/
			/* We are writting now, we do not need to read */
			if(close(fileDesPipe2[0]) == -1) {
				perror("Close error");
				exit(EXIT_FAILURE);
			}
			/* Writting process */
			nbytes = write(fileDesPipe2[1], writer = getNumbersKind(buffer), BSIZE);
			if(nbytes == -1) {
				perror("Error when writting");
				exit(EXIT_FAILURE);
			}
			else printf("CHILD: I have written %s in pipe 2\n", writer);
			/* Pipe closing */
			if(close(fileDesPipe2[1]) == -1) {
				perror("Close error");
				exit(EXIT_FAILURE);
			}
			else printf("CHILD: Closed pipe 2\n");
			break;

		default: /* FATHER */
			/*-------------------------WRITTING------------------------------*/
			/* We are writting, so we do not need to read*/
			if(close(fileDesPipe1[0]) == -1) {
				perror("Close error");
				exit(EXIT_FAILURE);
			}
			/* Writting process */
			nbytes = write(fileDesPipe1[1], writer = askNumbers(), BSIZE);
			if(nbytes == -1) {
				perror("Error when writting pipe");
				exit(EXIT_FAILURE);
			}
			else printf("FATHER: I have wrote %s to pipe 1\n", writer);
			/* Pipe closing */
			if(close(fileDesPipe1[1])) {
				perror("Close error");
				exit(EXIT_FAILURE);
			}
			else printf("FATHER: Closed pipe 1\n");
			/*------------------------READING--------------------------------*/
			/* We will read, write should be closed */
			if(close(fileDesPipe2[1]) == -1) {
				perror("Close error");
				exit(EXIT_FAILURE);
			}
			/* Reading process (blocking call) */
			nbytes = read(fileDesPipe2[0], buffer, BSIZE);
			if(nbytes == -1) {
				perror("Error when reading pipe");
				exit(EXIT_FAILURE);
			}
			else if (nbytes == 0) printf("FATHER: Child closed the pipe");
			else printf("FATHER: I have read %s from pipe 2\n", buffer);
			/* Pipe closing */
			if(close(fileDesPipe2[0])) {
				perror("Close error");
				exit(EXIT_FAILURE);
			}
			else printf("FATHER: Closed pipe 2\n");
			/*-------------------------WAITING--------------------------------*/
			while((pid = wait(&status)) > 0) {
				if(WIFEXITED(status)) printf("Child %d finished with %d status\n", pid, status);
			}
			if(pid == -1) {
				printf("There are no more childs\n");
				exit(EXIT_FAILURE);
			}
			break;
	}
	return 0;
}

int isPrime(int number) {
	if(number <= 1) return 0;
	if(number % 2 == 0 && number > 2) return 0;
	for(int i = 3; i < number / 2; i+= 2) {
		if(number % i == 0)
		return 0;
	}
	return 1;
}

char *getNumbersKind(char *buffer) {
	char *c_number1 = NULL;
	char *c_number2 = NULL;
	int number1;
	int number2;
	c_number1 = strtok(buffer, ";");
	c_number2 = strtok(NULL, ",");
	number1 = atoi(c_number1);
	number2 = atoi(c_number2);
	if(isPrime(number1) && isPrime(number2)) {
		if((abs(number1 - number2) == 2)) return "twins";
		else return "primes";
	}
	else return "no-primes";
}

char *askNumbers() {
	char number1[10];
	char number2[5];
	char *result = NULL;
	printf("Introduce two numbers:\n");
	printf("Number 1: ");
	scanf("%s", number1);
	printf("Number 2: ");
	scanf("%s", number2);
	strcat(number1, ";");
	strcat(number1, number2);
	result = number1;
	return result;
}