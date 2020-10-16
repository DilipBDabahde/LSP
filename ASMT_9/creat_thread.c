/*
	1. Write a program which is used to create simple thread by using pthread library.
	
	$gcc myfile.c -o myexe -lpthread -w
	$./myexe
*/

#include<stdio.h>
#include<pthread.h>


void *gun(void *ival)
{
	for(int i = 1; i <= (int)ival; i++)
	{
			printf("Hello gun\n");
	}	
	pthread_exit(NULL);
}


int main()   //main thread of exe
{
	printf("Inside main\n");
	
	pthread_t t1;
	int iNo = 5;
	int ret;
	int status;
	
	ret = pthread_create(&t1, NULL, (void*)gun, (void*)iNo);
	
	
	pthread_join(t1, &status);
	
	printf("status : %d\n",status);

	
	return 0;
}
