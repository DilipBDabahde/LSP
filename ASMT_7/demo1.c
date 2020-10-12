#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	int pid = getpid();
	
	printf("demo1 pid: %d\n",pid);
	if(pid > 0)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
}
