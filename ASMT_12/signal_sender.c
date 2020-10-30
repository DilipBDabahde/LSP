/*
5. Write a program which creates two process as sender and receiver in which sender process
   send signal to receiver process.

   Sender_Process
   
   this is sender process in this process we create one child process from that child process space we exec receiver 
   process and receiver process runs in loop then after some time slice from sender process signal pass to receiver 
   process and receiver process display signal msg and exit from receiver process and back to sender process
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	pid_t pid;
	
	
	pid = fork();	//create process		
	if(pid == -1)
	{
		printf("errot to create receiver process\n");
		exit(-1);
	}

	if(pid == 0)
	{
		execl("./receiver", "", NULL);
	}	
	else
	{
		sleep(3);
		printf("ppid  : %d\n",getpid());
		kill(pid,SIGQUIT);	//after 3 seconds kill get call to child process
		printf("sender send singal\n");
		sleep(3);
		exit(0);		
	}

	exit(0);
}
