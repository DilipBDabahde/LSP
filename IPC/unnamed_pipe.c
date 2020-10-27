//Application program for Unnamed pipe
/*
	in this app we read from pipe and write to pipe
	before that we need to creat to thing
	one for write to pipe, and one for read from pipe
	
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define READEND 0
#define WRITEEND 1

int main()
{	
	int pipFDs[2]; //[0] to read, [1] to write into pipe
	
	char buf;  //1bytes buffer
	const char *msg = "I like to play cricket\n";
	
	printf("Demonstration of IPC using Unnamed Pipe\n");
	
	if(pipe(pipFDs) < 0) //creating pipe
	{
		perror("Pipe creation failed");
		exit(-1);	
	}
	
	
	
	pid_t pid =fork(); //creating child proc
	if(pid == -1)
	{
		perror("fork failed");
		exit(-1);
	}
	
	if(pid == 0)		//child process reading data from pipe
	{
		printf("Child process is running\n");
		close(pipFDs[WRITEEND]); // pipe close wr
		
		printf("Data received from parent process\n");
		
		while(read(pipFDs[READEND], &buf, 1) > 0)
		{
			write(1, &buf, sizeof(buf));
		}
			
		close(pipFDs[READEND]);
	
		_exit(0);	
	}
	else		//parent process write data to pipe
	{
		printf("Parent process is running\n");
		
		close(pipFDs[READEND]);
		
		write(pipFDs[WRITEEND],msg, strlen(msg));
		
		close(pipFDs[WRITEEND]);
		
		printf("Data is successfully written into pipe by parent process\n");
		
		wait(NULL);
		
		exit(0);	
	}
		
	return 0;
}
