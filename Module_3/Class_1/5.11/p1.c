#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int fd;
	size_t size;
	fd = atoi (argv[1]);
	size = write(fd, "Привет мир!\0", 21);
	if(size != 21)
	{
		printf("Не могу записать всю строку!\n");
		exit(-1);
	}
	return 0;
}
