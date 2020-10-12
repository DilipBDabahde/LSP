/*
	in this program we execute another file using execv
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	pid_t pid;

	
		
	pid = fork();  //creating child process
	
	if(pid == -1)
	{
		printf("Error to create new child process\n");
		exit(-1);
	}
	
	if(!pid)
	{
		printf("process created successfully with pid: %d\n",getpid());
					
		char *args[] = {"./abc", NULL};  //array of vectors
		int ret;
		
		ret = execv(args[0], args); //executing child process
		
		if(ret == -1)
		{
			printf("error to execute child process\n");
			exit(EXIT_FAILURE);
		}	
	}
	else
	{
		printf("parent id: %d\n",getpid());	
	}	
	

	return 0;
}
