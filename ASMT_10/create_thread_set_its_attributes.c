/*
2. Write a program which creates multiple threads and sets its thread attributes accordingly.

$ gcc test1.c -o myexe  -lpthread -w
$ myexe

*/

#include<stdio.h>
#include<pthread.h>

void *fun(void* ptr)
{
	printf("val is : %d\n",(int)ptr);
	
	pthread_exit(NULL);
}

int main()
{
	pthread_attr_t attrs[4];			//array of struct objs
	pthread_t  	   threads[4];			//array of threads
	int arr[] = {10,20,30,40}, status = 0;
	
	//initializing 4 obj attributes with default values
	for(int i = 0; i < sizeof(attrs)/sizeof(attrs[0]); i++)
	{
		pthread_attr_init(&attrs[i]);
	}
	
	
	for(int i = 0; i < sizeof(threads)/sizeof(threads[0]); i++)
	{
		pthread_create(&threads[i], &attrs[i], (void*)fun, (void*)arr[i]);
	}
	
	
	//waiting till theads rejoin to main thread	
	for(int i = 0; i < sizeof(threads)/sizeof(threads[0]); i++)
	{
		pthread_join(threads[i], &status);
		printf("Thread Number: %d   <--->  thread status : %d\n",i+1, status);
	}
		
	
	//freeing 4 obj attributes with default values
	for(int i = 0; i < sizeof(attrs)/sizeof(attrs[0]); i++)
	{
		pthread_attr_destroy(&attrs[i]);
	}
	

	pthread_exit(0); //main thread
}

//no syncronization in this application
