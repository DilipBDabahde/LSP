/*
4. Write a program which creates two thread , and by using appropriate synchronization technique	
   avoid the scheduling problem.

output: 
	syncronized output display
	
$ gcc test1.c -o myexe  -lpthread -w
$ myexe

*/

#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;


void *fun(void* ptr)
{	
	pthread_mutex_lock(&lock);    		//acquire lock
	
	for(int i = 1; i <= (int)ptr; i++)
	{
		printf("fun : %d\n", (int)ptr);
	}
	
	printf("\n");
	pthread_mutex_unlock(&lock);    		//release lock
	
	pthread_exit(NULL);
}

int main()
{

	pthread_t  	   threads[2];			//array of threads
	int arr[] = {40, 80}, status = 0;
	
	
	//creating thread
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

