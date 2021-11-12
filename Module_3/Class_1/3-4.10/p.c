#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid, ppid, chpid;
	chpid = fork();
	if (chpid == -1)
	{
		printf("Ошибка!\n");
	}
	else
		if (chpid == 0)
		{
			printf("Я ребенок\n");
		}
		else
		{
			printf("Я родитель\n");
		}
	return 0;
} 
