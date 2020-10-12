/*
demonstration of parent and child process share TDSH with child
*/

#include<stdio.h>
#include<unistd.h>



int main()
{
	
	
	pid_t pid;
	
	int i = 10;   //auto local variable store into stack frame
	
	pid = fork();  //create child process
	
	if(pid == 0)  //child process area
	{
		//child process region
		printf("%d\n",++i); 		//pre-increment
		printf("child pid: %d\n",getpid());	
	
	}
	else   		//parent process area
	{
		//parent process region
		printf("%d\n",++i); 		//pre-increment	
		printf("parent pid: %d\n",getpid());	
	
	}


	return 0;
}
