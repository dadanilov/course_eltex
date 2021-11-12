#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	(void) execle("/bin/cat", "/bin/cat", "p.c", 0, envp);
	printf("Ошибка при запуске программы.\n");
	exit(-1);
	return 0; 
}
