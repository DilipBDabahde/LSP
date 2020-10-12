/*
	Demonstration of wait(int *) to get child termination status
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{
	int ret = 0;
	
	ret = vfork();
	
	if(ret == 0)
	{
		printf("fork created new process value : %d\n",ret);
		printf("process id  of fork : %d\n",getpid());
		printf("parent of fork process : %d\n",getppid());
		exit(0);
	}
	else
	{
		printf("current exe process id: %d\n",getpid());
		printf("parent of exe process id: %d\n",getppid());
		printf("fork process id: %d\n",ret);
		
	}
	
	
	int *p = NULL;
	ret = wait(p);
	printf("after wait %d\n",ret);



	return 0;
}
