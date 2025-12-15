
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 128
#define CHILD 0


int main(void){
	char buffer[BUFSIZE]= "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash % ";
	write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));
	while (1) {
		char input[BUFSIZE] = "";
		read(STDIN_FILENO, input, BUFSIZE);

		char* token = strtok(input," \n");
		if (token != NULL) {
			if (strncmp(token, "exit", BUFSIZE) == 0) {
				strncpy(buffer, "A bientôt !\n", BUFSIZE);
				write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));
				return EXIT_SUCCESS;
			}

			int pid, status;
			if ((pid = fork()) != CHILD) { //
				wait(&status);

				if (WIFEXITED(status)) {  // If child stops
					snprintf(buffer, BUFSIZE,"\nenseash [exit : %d] %%", WEXITSTATUS(status));
				}else if (WIFSIGNALED(status)) { // If signal stops child
					snprintf(buffer, BUFSIZE,"\nenseash [sign : %d] %%", WTERMSIG(status));
				}

				write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));
			}else { 
				execlp(token, token, (char*)NULL);
				sprintf(buffer, "Error while running %s",token);
				write(STDERR_FILENO, buffer, strnlen(buffer,BUFSIZE));
				exit(EXIT_FAILURE);
			}
		}
	}
}
