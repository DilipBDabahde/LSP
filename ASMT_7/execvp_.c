
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{

	
	pid_t pid;
	int status = 0;
	
	char *argv[] = {"./proc", NULL};
	
	
	pid = fork();
	
	 if(pid == 0)
	{
		printf("fork pid : %d\n",getpid());
		execvp(argv[0],argv);
	}
	
	
	exit(0);
}
