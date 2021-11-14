#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int msqid; 
	char pathname[] = "p_server.c"; 
	key_t key; 
    	int len; 
	long i;
	struct mymsgbuf
	{
		long mtype;
		int msg;
	} mybuf;
	if ((key = ftok(pathname, 0)) < 0)
    	{
		printf("Не могу сгенерировать ключ\n");
		exit(-1);
	}
	if ((msqid = msgget(key, 0666 | IPC_CREAT)) < 0)
    	{
		printf("Не могу получить msqid\n");
		exit(-1);
	}
	while (1)
    	{
		if (len = (msgrcv(msqid, (struct msgbuf *) &mybuf, sizeof(int), 1, 0) < 0))
        	{
			printf("Не могу получить сообщение из очереди\n");
			exit(-1);
		}
        	printf("Получено сообщение от процесса с PID = %d, ", mybuf.msg);
		for (i = 0; i < 500000000L; i++); 
		printf("Отправлено сообщение\n");
        	mybuf.mtype = mybuf.msg; 
	    	if (msgsnd(msqid, (struct msgbuf *) &mybuf, 0, 0) < 0)
        	{
	        	printf("Не удается отправить сообщение в очередь\n");
	        	exit(-1);
	    	}
	}
	return 0;
}
