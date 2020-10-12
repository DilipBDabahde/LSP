/*
	1.Write a program which creates one child process, and parent process waits till its child process terminates.
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{
	int ret , status;
	
	ret = status = 0;
	
	ret = fork(); //call to create new process / child process
	
	if(ret == 0)		//child area
	{
		//child is gonna perform something
		printf("fork created process id : %d\n",getpid());
		printf("parent of fork process : %d\n",getppid());
		printf("current value of ret : %d\n\n",ret);
		exit(0); //to terminate child process
	}
	else		    	//parent area
	{
		//penent is gonna perform something
		printf("Parent process id: %d\n",getpid());
		printf("parent to parent process id: %d\n",getppid());
		printf("fork created process id with parent area: %d\n\n",ret);	
		wait(NULL);														//<-- req to parent wait till child terminate
		printf("parent wait till child terminate\n\n");
	}

	
	exit(0);
}
