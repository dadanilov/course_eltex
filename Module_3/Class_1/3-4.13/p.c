#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{	
	printf("%d\n%s\n%s\n",argc,argv[1],argv[2]);	
}
