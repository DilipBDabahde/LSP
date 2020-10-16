/*
5. Write a program which is used to get thread id inside its thread function.
   
	$gcc myfile.c -o myexe -lpthread -w
	$./myexe
	-lpthread  <-  compile with pthread library
	-w 		  <- skill warning
*/

#include<stdio.h>
#include<pthread.h>

void *child_tid(void *ptr)
{
	printf("child thread id: %ld\n",pthread_self());	
	
	pthread_exit(NULL);
}

int main()   //main thread of exe
{
	pthread_t t1;
	int ret, status;
	
	printf("main thread id: %ld\n",pthread_self());
	
	ret = pthread_create(&t1, NULL, (void*)child_tid, (void*)NULL);
	
	if(ret != 0)
	{
		printf("error to create child thread\n");
		return -1;
	}

	pthread_join(t1, &status);
	
	printf("child thread status: %d\n",(int)status);
	printf("terminating main thread\n");
	
	return 0;
}
