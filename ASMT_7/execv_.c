
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{

	
	pid_t pid;
	int status = 0;
	int ret;
	
	char *argv[] = {"./Test.c",NULL};
	
	pid = fork();
	
	 if(pid == 0)
	{
		printf("pid : %d\n",getpid());	
		ret = execvp(argv[0],argv);
	}
	else
	{				
		pid = wait(&status);
		printf("Child status : %d\n",status);
		printf("parent wait till child term cpid : %d\n",pid);
		printf("parent pid  : %d\n\n",getpid());
	}
	
	if(ret == -1)
		{
			perror("execvp: ");
		}
	
	exit(0);
}
