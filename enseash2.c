
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024


int main(int argv, char **argc){
	char* buffer;
	if(argv != 1) {
		buffer = "wrong number of arguments";
		write(STDERR_FILENO, buffer, strnlen(buffer,BUFSIZE));
		return EXIT_FAILURE;
	}
	buffer = "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash % ";
	write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));
	while (1) {
		char input[BUFSIZE] = "";
		read(STDIN_FILENO, input, BUFSIZE);

		char* token = strtok(input," \n");
		if (token != NULL) {
			if (strncmp(token, "exit", BUFSIZE) == 0) {
				buffer = "A bientôt !\n";
				write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));
				return EXIT_SUCCESS;
			}
			int pid, status;
			if ((pid = fork()) != 0) {
				wait(&status);
				//print ?
				buffer = "\nenseash % ";
				write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));
			}else {
				execlp(token, token, (char*)NULL);
				buffer = strncat("Error while running ",token, BUFSIZE);
				write(STDERR_FILENO, buffer, strnlen(buffer,BUFSIZE));
				exit(EXIT_FAILURE);
			}
		}
	}
}
