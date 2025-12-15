
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 128
#define EXIT_QUERY "exit"
#define CHILD 0


int main(void){
	char buffer[BUFSIZE]= "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash % ";
	write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));
	while (1) {
		char input[BUFSIZE] = "";
		read(STDIN_FILENO, input, BUFSIZE);

		char* token = strtok(input," \n");
		if (token != NULL) {
			if (strncmp(token, EXIT_QUERY, BUFSIZE) == 0) {
				strncpy(buffer, "A bientôt !\n", BUFSIZE);
				write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));
				return EXIT_SUCCESS;
			}



			struct timespec timer_start;
			struct timespec timer_end;
			clock_gettime(CLOCK_REALTIME, &timer_start);

			int pid, status;
			if ((pid = fork()) != CHILD) { // Création de l'enfant
				wait(&status);
				clock_gettime(CLOCK_REALTIME, &timer_end);
                int delay = timer_end.tv_sec*1e3 - timer_start.tv_sec*1e3 + timer_end.tv_nsec*1e-6 - timer_start.tv_nsec*1e-6;

				if (WIFEXITED(status)) {  // If child stops normally
					snprintf(buffer, BUFSIZE,"\nenseash [exit : %d|%dms] %%", WEXITSTATUS(status), delay);
				}
                
                else if (WIFSIGNALED(status)) { // If signal stops child
					snprintf(buffer, BUFSIZE,"\nenseash [sign : %d] %%", WTERMSIG(status), delay);
				}

				write(STDOUT_FILENO, buffer, strnlen(buffer,BUFSIZE));

			}
            
            else { 
				execlp(token, token, (char*)NULL);
				sprintf(buffer, "Error while running %s",token);
				write(STDERR_FILENO, buffer, strnlen(buffer,BUFSIZE));
				exit(EXIT_FAILURE);
			}
		}
	}
}
