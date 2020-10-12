/*
	create process and execute other file from thatn newly created process
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv, char **env)
{
	
	int ret = 0;
	
	
	if((ret = fork()) == 0)
	{
		printf("fork created process id: %d\n",getpid());
		printf("Parent of fork process : %d\n",getppid());		
		execl("./proc","", NULL);	
	}
	else
	{
		printf("Parent process id: %d\n",getpid());
		printf("Parent to Parent process id: %d\n",getppid());
		printf("fork created pid: %d\n",ret);	
	}

	exit(0);
}
