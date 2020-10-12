/*
	exit call will terminate everything about running process statistics and went to zombie state
*/

#include<stdio.h>
#include<stdlib.h>


void fun()
{
		
	printf("start fun\n");
	exit(0);
	printf("end of fun\n");
}

int main()
{
	
	printf("start main\n");
	fun();
	printf("end of main\n");

	return 0;
}
