
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 1024

int main(int argv, char **argc){
	char* buffer;
	if(argv != 1) {
		buffer = "wrong number of arguments";
		write(STDERR_FILENO, buffer, strnlen(buffer, MAX_LEN));
		return EXIT_FAILURE;
	}
	buffer = "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash %";
	write(STDOUT_FILENO, buffer, strnlen(buffer, MAX_LEN));
	
	return EXIT_SUCCESS;
}
