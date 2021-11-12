#include <unistd.h>
#include <stdio.h>

int main()
{
	int pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("Мой ID = %d, ID родителя = %d\n", (int)pid, (int)ppid);
	return 0;
} 
