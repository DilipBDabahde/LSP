/*
3. Write a program which creates one child process , child process write something in
   unamed pipe and parent process read the data from that pipe.
   
   
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAXSIZE 1024

int main()
{
	int fds[2];
	pid_t pid;
	char buff[MAXSIZE] = {'\0'};
	
	if(pipe(fds) == -1) //create unmaed pipe
	{
		printf("pipe failed\n");
		exit(-1);	
	}
	
	pid = fork();
	
	if(pid == -1)
	{
		printf("fork failed\n");
		exit(-1);
	}
	
	if(pid == 0)  //child process area
	{
		if(close(fds[0]) == -1)		//pipe read end closed
		{
			printf("error to close read end\n");
			exit(-1);
		}
		
		//write data to pipe
		write(fds[1], "Hello from child msg to parrent", strlen("Hello from child msg to parrent")+1);
		
		if(close(fds[1]) == -1)		//pipe write end closed
		{
			printf("error to close write end\n"); 
			exit(-1);
		}
		_exit(EXIT_SUCCESS);
	}
	else		//parent process area
	{	
		int status, ret;
		wait(&status);	//parent wait till child terminate
		
		if(close(fds[1]) == -1)		
		{
			printf("error to close write end\n");
			exit(-1);
		}
		
		printf("child process status: %d\n",status);
		
		while((ret = read(fds[0], buff, sizeof(buff))) > 0)
		{
			write(STDOUT_FILENO, buff, ret);
		}
		
		write(1, "\n",1);
		
		if(close(fds[0]) == -1)		
		{
			printf("error to close read end\n");
			exit(-1);
		}
		
		exit(EXIT_SUCCESS);		
	}	
}
