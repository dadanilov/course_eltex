#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int msqid;
	char pathname[] = "p_server.c"; 
	key_t key; 
    	int pid = getpid(); 
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
    	mybuf.mtype = 1; 
	mybuf.msg = pid; 
	if (msgsnd(msqid, (struct msgbuf *) &mybuf, sizeof(int), 0) < 0)
    	{
		printf("Не могу отправить сообщение в очередь\n");
		exit(-1);
	}
	printf("Отправлено сообщение, PID = %d, ", pid);
	if ((msgrcv(msqid, (struct msgbuf *) &mybuf, 0, pid, 0) < 0))
    	{
		printf("Не могу получить сообщение из очереди\n");
		exit(-1);
	}
	printf("Получено сообщение\n");
	return 0;
}
