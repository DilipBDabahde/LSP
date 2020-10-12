#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

	pid_t pid;
	
	pid = fork();
	
	if(pid > 0)
	{
		printf("i am parent of pid: %d\n",pid);
	}
	else if(!pid)
	{
		printf("i am child : %d\n",pid);
	}
	else if(pid == -1)
	{
		perror("fork");
	}


	exit(0);
}
