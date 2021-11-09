#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>
int main()
{
	int shmid, i = 0, len = 0;
	char *array,pathname[]="result.c", a;
	key_t key;
	FILE *f = fopen("p2.c","r");
	if ((key = ftok(pathname, 0)) < 0)
	{
		printf("Ошибка: не удается сгенерировать ключ.\n");
	}
	if ((shmid = shmget (key, 1280*sizeof (char), 0666 | IPC_CREAT|IPC_EXCL)) < 0)
	{
		if (errno != EEXIST)
		{
			printf("Ошибка: не удается создать общую память.\n");
		}
		else
		{
			if ((shmid = shmget (key, 1280*sizeof (char), 0)) < 0)
			{
				printf("Ошибка: не удается найти общую память.\n");
			}
		}
	}
	if ((array=(char *)shmat(shmid, NULL, 0)) == (char *)(-1))
	{
		printf("Ошибка: не удается подключить общую память.\n");
	}
	for (i = 0; i < 1280; i++)
	{
		printf("%c",array[i]);
	}
	if (shmdt(array) < 0)
	{
		printf("Ошибка: не удается отсоединить общую память.\n");
	}
	pclose(f);
	return 0;
}
