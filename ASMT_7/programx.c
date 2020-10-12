#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	
	printf("in child process pid: %d\n",getpid());
	printf("parent id : %d\n",getppid());
	sleep(5);
	printf("parent id : %d\n",getppid());
	
	exit(0);
	
	
}
