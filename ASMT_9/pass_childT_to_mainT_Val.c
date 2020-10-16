/*
4. Write a program which creates single thread and it accept one value from
   user and it return some value to the caller thread.
    
   
	$gcc myfile.c -o myexe -lpthread -w
	$./myexe
	-lpthread  <-  compile with pthread library
	-w 		  <- skill warning
*/

#include<stdio.h>
#include<pthread.h>


void *AcceptValue(void *ptr)
{
	int ival = 0;
	printf("Enter value: ");
	scanf("%d",&ival);
	
	pthread_exit(ival);
}


int main()   //main thread of exe
{

	pthread_t t1;
	int ret1;
	int status1;	
	
	//create first thread	
	ret1 = pthread_create(&t1, NULL, (void*)AcceptValue, (void*)NULL);
	
	if(ret1 != 0)
	{
		printf("Error to create thread 1\n");
		return -1;
	}

	
	//wait till thread gets exits and return status
	
	pthread_join(t1, &status1);
	printf("Status of t1 is accepted value : %d\n",(int)status1);
	printf("Terminating main thread\n");
	return 0;
}
