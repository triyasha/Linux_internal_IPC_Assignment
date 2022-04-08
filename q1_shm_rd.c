/*
11.write a program that creates a shared memory region and displays shared memory id and also
print address at which shared area in this process starts from.
*/


#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

#define KEY 200

int main()
{
	int shmid;
	char *t;

	shmid = shmget(KEY, 250, IPC_CREAT|0664);
	if(shmid < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory ID is : %d\n",shmid);

	t = shmat(shmid, 0, 0);

	printf("Address at which shared memory start is: %p\n",t);
	printf("Data is: %s\n",t);

	return 0;
}
