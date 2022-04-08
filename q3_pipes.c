//3.Write a program parent process writing to pipe and child reading toggled data from pipe,


#include<stdio.h>
#include<unistd.h>
#include <string.h>
#include<stdlib.h>

int fds[2];

char* kh_toggle(char k_string[])
{
	char* kh_returnstring=k_string;
	for(int i=0; i<strlen(k_string); i++)
	{
		if(kh_returnstring[i]>='A' && kh_returnstring[i]<='Z')
		kh_returnstring[i]=kh_returnstring[i]+32;
		else if(kh_returnstring[i]>='a' && kh_returnstring[i]<='z')
		kh_returnstring[i]=kh_returnstring[i]-32;
	}
	return kh_returnstring;
}

int main()
{
	int kh_result;
	pid_t pid;
	kh_result = pipe(fds);
	if(kh_result==-1)
	{
		perror("pipe");
		exit(1);
	}
		pid = fork();
	if(pid==0)
	{
		char buf_to_read[100];
		int n;
		n = read(fds[0], buf_to_read, 100);
		for(int i=0; i<n; i++)
		{
		printf("%c", buf_to_read[i]);
		}
	}
	else
	{
		char buf1[20] = "this is buffeR 1"; //Letters written in lower case turn to upper case and vice versa (only last bit)
		char buf2[20] = "this is buffeR 2";
		char *b1 = kh_toggle(buf1);
		char *b2 = kh_toggle(buf2);
		write(fds[1], b1, 20);
		//printf("\n");
		write(fds[1], b2, 20);
		//printf("\n");
		}
	return 0;
}
