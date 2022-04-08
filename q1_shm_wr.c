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
	char *p;

	shmid = shmget(KEY, 250, IPC_CREAT|0664);
	if(shmid < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory id: %d\n",shmid);

	p = shmat(shmid, 0, 0);
	printf("Address at which shared memory start is: %p\n",p);

	printf("Enter the data: \n");
	scanf("%s", p);


	return 0;
}
