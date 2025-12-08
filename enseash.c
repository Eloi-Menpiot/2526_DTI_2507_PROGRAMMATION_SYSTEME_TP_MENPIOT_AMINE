
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argv, char **argc){
	char* buffer;
	int max_len = 1024;
	if(argv != 1) {
		buffer = "wrong number of arguments";
		write(STDERR_FILENO, buffer, strnlen(buffer,max_len));
		return EXIT_FAILURE;
	}
	buffer = "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash %";
	write(STDOUT_FILENO, buffer, strnlen(buffer,max_len));
	
	return EXIT_SUCCESS;
}
