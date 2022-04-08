/*
2.write a program that uses msgctl() and prints number of messages,number of bytes in message
queue and also get Maximum number of bytes in queue for already existing message queue
and also remove message queue at the end.
*/


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

#define key 200

struct msg_qu
{
	long mytype;
	char data[512];
};

int main()
{
	int mid;
	struct msg_qu q1, q2;
	struct msqid_ds mybuff;

	mid = msgget(key, IPC_CREAT|0664);
	if(mid < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Message queue id: %d\n",mid);

	msgctl(mid, IPC_STAT, NULL);

	printf("Contents from the struct are: \n");
	printf("no of msges in queue: %d\n",mybuff.msg_qnum);
	printf("no of bytes in queue: %d\n",mybuff.msg_cbytes);
	printf("max no of bytes in queue: %d\n",mybuff.msg_qbytes);

	msgrcv(mid, &q1, sizeof(q1), 2, 0);

	printf("Type1 is: %ld\n",q1.mytype);
	printf("Message1 is: %s\n",q1.data);

	msgrcv(mid, &q2, sizeof(q2), 3, 0);

	printf("Type2 is: %ld\n",q2.mytype);
	printf("Message2 is: %s\n",q2.data);

	msgctl(mid, IPC_RMID, NULL);

	return 0;
}
