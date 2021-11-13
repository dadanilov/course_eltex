#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd[2], result;
	char spf[2][50];
	if (pipe(fd) < 0)
	{
		printf("Не могу создать pipe\n");
		exit(-1);
	}
	sprintf(spf[0], "%d", fd[0]);
	sprintf(spf[1], "%d", fd[1]);
	result = fork();
	if (result <0)
	{
		printf("Не могу развить ребенка\n");
		exit(-1);
	} else 
		if (result > 0) 
		{
			close(fd[0]);
			execl("./p1", "p1", spf[1], NULL);
		} 
		else 
		{
			close(fd[1]);
			execl("./p2", "p2", spf[0], NULL);
		}
	return 0;
} 
