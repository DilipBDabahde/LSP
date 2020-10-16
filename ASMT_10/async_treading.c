/*
3 . Write a program which is used to predict the problem due to lack of synchronization.

output: 
	asyncronized output display
	
$ gcc test1.c -o myexe  -lpthread -w
$ myexe

*/

#include<stdio.h>
#include<pthread.h>

void *fun(void* ptr)
{	
	for(int i = 1; i <= (int)ptr; i++)
	{
		printf("fun : %d\n",(int)ptr);
	}

	printf("\n");	
	pthread_exit(NULL);
}

int main()
{

	pthread_t  	   threads[4];			//array of threads
	int arr[] = {3,5,7,2}, status = 0;
	
	
	
	for(int i = 0; i < sizeof(threads)/sizeof(threads[0]); i++)
	{
		pthread_create(&threads[i], NULL, (void*)fun, (void*)arr[i]);
	}
	
	
	//waiting till theads rejoin to main thread	
	for(int i = 0; i < sizeof(threads)/sizeof(threads[0]); i++)
	{
		pthread_join(threads[i], &status);
		printf("Thread Number: %d   <--->  thread status : %d\n",i+1, status);
	}

	pthread_exit(0); //main thread
}


