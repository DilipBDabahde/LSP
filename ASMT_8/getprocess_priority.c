/*
4.Write a program which is used to print priority of current process.
	
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>


int main()
{
	
	
	int prio;
	
	prio  = getpriority(0, PRIO_PROCESS);
	printf("process id : %d\n",getpid());
	printf("process nice value :%d\n",nice(0));
	printf("Process priority is: %d\n",prio);
	
	
	return 0;
}
