
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LEN 1024

int main(int argv, char **argc){
	char* buffer;
	if(argv != 1) {
		buffer = "Wrong number of arguments";
		write(STDERR_FILENO, buffer, strnlen(buffer, MAX_LEN));
		return EXIT_FAILURE;
	}
	buffer = "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash %";
	write(STDOUT_FILENO, buffer, strnlen(buffer, MAX_LEN));

	while(1){
		char input[MAX_LEN] = "";
		read(STDIN_FILENO, input, MAX_LEN);

		char * token = strtok(input, " \n");
		if (token != NULL){

			if(strncmp(token, "exit", MAX_LEN) == 0){
				buffer = "A bientôt !\n";
				write(STDOUT_FILENO, buffer, strnlen(buffer, MAX_LEN));
				return EXIT_SUCCESS;
			}

			int pid, status;
			if ((pid = fork()) != 0){
                wait(&status);
                buffer = "\nenseash % ";
                write(STDOUT_FILENO, buffer, strnlen(buffer, MAX_LEN));
			}

			else{
				execlp(token , token, (char*)NULL);
                buffer = strncat("Error while running", buffer, strnlen(buffer, MAX_LEN));
                write(STDOUT_FILENO, buffer, strnlen(buffer, MAX_LEN));
                exit(EXIT_FAILURE);
			}
		}
	}

	return EXIT_SUCCESS;
}
