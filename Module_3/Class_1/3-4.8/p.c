#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid, ppid, chpid;
	int a = 0;
	chpid = fork();
	a = a+1; 
	pid = getpid();
	ppid = getppid();
	printf("Мой PID = %d, мой PPID = %d, результат %d\n", (int)pid, (int)ppid, a);
	return 0;
} 
