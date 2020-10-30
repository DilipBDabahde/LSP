/*
2. Write a program which creates child process and parent process will communicate with
   child process by sending signals.
*/


#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <signal.h> 
#include<sys/wait.h>


void sigint();


int main() 
{ 
	pid_t pid; 

	pid = fork();
	
	if( pid == -1) 
	{ 
		perror("fork"); 
		exit(1); 
	} 

	if (pid == 0) 
	{ 
		signal(SIGINT, sigint); 	//corrosponsing function get invoked
	
		int i = 1;
		while(i)
		{
			printf("%d\n",i++);
		}
	} 

	else 
	{ 	printf("ppid: %d\n",getpid());
		sleep(1);	//when 5 seconds complete at once single pass to child process
		printf("parent send signal to child\n"); 
		kill(pid, SIGINT);
	} 
} 


void sigint() 
{ 
	signal(SIGINT, sigint); 
	printf("child says: received a SIGINT\n"); 
	exit(0);
} 
