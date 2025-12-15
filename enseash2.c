
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFSIZE 128
#define CHILD 0
#define EXIT_QUERY "exit"

int main(int argv, char **argc){
	char* buffer;
	if(argv != 1) {
		buffer = "Wrong number of arguments";
		write(STDERR_FILENO, buffer, strnlen(buffer, BUFSIZE));
		return EXIT_FAILURE;
	}
	buffer = "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash %";
	write(STDOUT_FILENO, buffer, strnlen(buffer, BUFSIZE));

	while(1){
		char input[BUFSIZE] = "";
		read(STDIN_FILENO, input, BUFSIZE);

		char * token = strtok(input, " \n");
		if (token != NULL){

			if(strncmp(token, EXIT_QUERY, BUFSIZE) == 0){
				buffer = "A bientôt !\n";
				write(STDOUT_FILENO, buffer, strnlen(buffer, BUFSIZE));
				return EXIT_SUCCESS;
			}

			int pid, status;
			if ((pid = fork()) != 0){
                wait(&status);
                buffer = "\nenseash % ";
                write(STDOUT_FILENO, buffer, strnlen(buffer, BUFSIZE));
			}

			else{
				execlp(token , token, (char*)NULL);
                buffer = strncat("Error while running", buffer, strnlen(buffer, BUFSIZE));
                write(STDOUT_FILENO, buffer, strnlen(buffer, BUFSIZE));
                exit(EXIT_FAILURE);
			}
		}
	}

	return EXIT_SUCCESS;
}
