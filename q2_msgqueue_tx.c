/****************************************************************************************************
 *
 * 2.write a program that uses msgctl() and prints number of messages,number of bytes in message 
 * queue and also get Maximum number of bytes in queue for already existing message queue
 * and also remove message queue at the end
 *
 * ***************************************************************************************************/


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

#define key 34

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
	
	q1.mytype = 2;
	strcpy(q1.data, "msg queue transmitter");

	q2.mytype = 3;
	strcpy(q2.data, " Triyasha ");

	msgsnd(mid, &q1, strlen(q1.data)+1, 0);
	perror("msgsnd1");

	msgsnd(mid, &q2, strlen(q2.data)+1, 0);
	perror("msgsnd2");
	msgctl(mid, IPC_STAT, NULL);
	
	printf("Contents from the struct are: \n");
	printf("no of msges in queue: %d\n",mybuff.msg_qnum);
	printf("no of bytes in queue: %d\n",mybuff.msg_cbytes);
	printf("max no of bytes in queue: %d\n",mybuff.msg_qbytes);

	return 0;
}
