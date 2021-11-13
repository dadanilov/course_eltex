#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int fd;
	size_t size;
	char resstring[21];
	fd = atoi(argv[1]);
	size = read(fd, resstring, 21);
	if(size < 0)
	{
		printf("Не могу прочитать строку!\n");
		exit(-1);
	}
	printf("%s",resstring);
	close(fd);
	return 0;
}
