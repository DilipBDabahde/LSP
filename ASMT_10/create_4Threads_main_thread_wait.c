/*
1. Write a program which creates 4 number of threads and our main thread waits till all the thread terminates.
*/


#include<stdio.h>
#include<pthread.h>

int icnt = 0;   //in non_bss data segment
pthread_mutex_t lock;     //lock variable created stored into bss data segment


void *Thread_count(void* args)		//syncronization 
{
	pthread_mutex_lock(&lock);  			//lock aquire 
		
	icnt++;
	
	for(int x = 1; x <= icnt; x++)
	{
		printf("Hello from Thread_count : %d \n",icnt);
	}
	printf("\n");
	
	pthread_mutex_unlock(&lock);			//release lock	
	pthread_exit(NULL);						//exit from child thread
}


int main()
{

	pthread_t threads[4];  //created array of {unsigned long int}
	int status = 0;
	
	//creating threads in loop		
	for(int i = 1; i <= sizeof(threads)/sizeof(threads[0]); i++)
	{
		pthread_create(&threads[i], NULL, &Thread_count, NULL);
	}
	
	//waiting for threads in loop
	for(int j = 1; j <= sizeof(threads)/sizeof(threads[0]); j++)
	{
		pthread_join(threads[j], &status);
		
		printf("Thread number : %d     <-->  Thread status : %d\n",j, status);
	}


	pthread_exit(0);  //end of main thread
}
