/*
1. Write a program which is used to create unnamed pipe. Parent process creates new child
   process and both the processess will communicate with each other.
   
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#define MAXSIZE 1024

int main()
{
	int fds[2], ret;
	char buff[MAXSIZE] = {'\0'};
	pid_t pid;
	
	if(pipe(fds) == -1)
	{
		printf("pipe failed\n");
		exit(-1);
	}
	
	
	//create child process
	
	if( (pid = fork()) == -1 )
	{
		printf("fork failed\n");
		exit(-1);
	}
	
	if(pid == 0)  //child process area
	{
		close(fds[1]); //pipe write end close
				
		while((ret = read(fds[0], buff, sizeof(buff))) > 0)
		{
			write(1, buff, ret);
		}
		
		close(fds[0]); //closing read end pipe		
		_exit(0);	
	}
	else	//parent process area
	{
		close(fds[0]); //pipe read end close in parent area
		
		write(fds[1], "Hello from parent\n", strlen("Hello from parent\n")+1);
		
		close(fds[1]); //reader will get EOF bcs of this close
		
		wait(NULL);		//parent wait till child terminate
		
		exit(EXIT_SUCCESS);			
	}		
}
