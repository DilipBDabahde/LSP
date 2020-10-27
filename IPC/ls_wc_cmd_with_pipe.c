/*
demonstration of 
$ ls | wc -l

for ls cmd one process fork and exec

for wc cmd one process fork and exec


step 1  create pipe
step 2 create 2 child process and exec one cmd each
step 3 parent wait till both child terminates

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>



int main()
{

	int fds[2];
	
	if(pipe(fds) == -1)
	{
		printf("error to create pipe\n");
		exit(-1);
	}
	
	//create first child
	
	switch(fork())
	{
		int ret;
		case -1:
			printf("fork\n");
			exit(-1);
		
		case 0:	
			if(close(fds[0]) == -1)  //close read end
			{
				exit(-1);
			}
		//duplicating stdout on write
		
		if(fds[1] != STDOUT_FILENO)	//cmp write end
		{
			if(dup2(fds[1], STDOUT_FILENO) == -1)	//cpy write ends
			{
				printf("error to dup2\n");
				exit(-1);
			}
			
			if(close(fds[1]) == -1)	//close write end
			{
				printf("error to close write end fds\n");
				exit(-1);
			}
		}
		
		execlp("ls", "ls", (char*)NULL);  //write to pipe
		if(ret == -1)
		{
			printf("execlp error\n");
			exit(-1);
		}
			exit(0);
	
		default:		//parent fall down
			break;	
	}
	
	//create second child
	
	switch(fork())
	{	
		int ret;
		case -1:
			printf("fork\n");
			exit(-1);
		
		case 0:
			if(close(fds[1]) == -1)
			{
				printf("error to write end\n");
				exit(-1);
			}
			
			if(fds[0] != STDIN_FILENO)
			{
				if(dup2(fds[0], STDIN_FILENO) == -1)
				{
					printf("dup2 error\n");
					exit(-1);
				}
				
				if(close(fds[0]) == -1)
				{
					printf("error to read end\n");
					exit(-1);
				}
			}
			
			ret = execlp("wc", "wc", "-l", (char*)NULL);
			if(ret == -1)
			{
				printf("execlp error\n");
				exit(-1);
			}
			exit(0);
		
		default:
			break;	
	}
	
	if(close(fds[0] == -1))
	{
		printf("error to read ends\n");
		exit(-1);
	}
	
	if(close(fds[1]) == -1)
	{
		printf("error to write ends\n");
		exit(-1);
	}
	
	if(wait(NULL) == -1)
	{
		printf("wait error 1\n");
		exit(-1);
	}

	if(wait(NULL) == -1)
	{
		printf("wait error 2\n");
		exit(-1);
	}


	exit(EXIT_SUCCESS);
}
