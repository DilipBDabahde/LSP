/*
	in this program we create one child process and exec another executable file and after execution of that 
	file check its termiation status
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	pid_t pid;
	
	
	pid = fork();
	
	if(pid == 0)
	{
		printf("child pid: %d\n",getpid());
		
		execl("./demo1","", NULL);
	}
	else
	{	
		printf("parent pid: %d\n",getpid());
	}
	
	
	
	return 0;
}
