
#include <unistd.h>
#include <string.h>





int main(int argv, char *argc){
	write(STDOUT_FILENO, "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\nenseash % \n", 83);
}
