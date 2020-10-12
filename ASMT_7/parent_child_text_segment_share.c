/*
	demonstration of parent text copy create for child
*/
//text section contains executable instruction of our program file

#include<stdio.h>
#include<unistd.h>


void fun()
{	

	printf("Hello fun\n");
}

int main()
{
	
	pid_t  pid;
	
	pid = fork();
	
	if(pid == 0)  //child runs
	{
		fun(); //calls from child process area
		printf("child pid: %d\n",getpid());
	}
	else
	{
		fun();  //calls from parent process area
		printf("parent pid: %d\n",getpid());
	}

	return 0;
}
