/*
	vfork create process but does not create seperate copy of parent process till child exec new image 
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	
	
	pid = vfork(); //not create new copy of TDS for child so child use parent process to run printf statment into 
				  //parent process area
	
	if(pid == 0)	//child process area
	{		
		printf("child pid: %d\n",getpid()); // instead of this printf call use exec
		execl("./demo","",NULL);
	}
	else	//process area
	{
		printf("parent pid: %d\n",getpid());	
	}
	return 0;
}
