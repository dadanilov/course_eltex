#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>
#include <stdlib.h>

int main()
{
	int shmid, i = 0;
	char *array, pathname[] = "p1.c";
	key_t key;
	FILE *f;
	if ((key = ftok(pathname, 0)) < 0)
	{
		printf("Ошибка: не удается сгенерировать ключ.\n");
	}
	if ((shmid = shmget (key, 1280*sizeof (char), 0)) < 0)
	{	
		printf("Ошибка: не удается найти общую память.\n");
		exit(-1);
	}
	if ((array = shmat(shmid, NULL, 0)) == (char *) - 1)
	{
		printf("Ошибка: не удается подключить общую память.\n");
		exit(-1);
	}
	printf("%s\n",array);
	if (shmdt(array) < 0)
	{
		printf("Ошибка: не удается отсоединить общую память.\n");
	}
	return 0;
}
