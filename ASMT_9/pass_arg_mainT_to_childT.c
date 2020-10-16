/*
3. Write a program which creates single thread and we have to pass
   parameter to that thread from main thread.
   
   
	$gcc myfile.c -o myexe -lpthread -w
	$./myexe
	-lpthread  <-  compile with pthread library
	-w 		  <- skill warning
*/

#include<stdio.h>
#include<pthread.h>


void *Display(void *ptr)
{
	printf("My name is: %s\n",(char*)ptr);
	pthread_exit(NULL);
}


int main()   //main thread of exe
{

	pthread_t t1;
	int ret1;
	int status1;	
	char arr[] = {"Devid"};
	
	//create first thread
	
	ret1 = pthread_create(&t1, NULL, (void*)Display, (void*)arr);
	
	if(ret1 != 0)
	{
		printf("Error to create thread 1\n");
		return -1;
	}

	
	//wait till thread gets exits and return status
	
	pthread_join(t1, &status1);
	printf("Status of t1 is : %d\n",status1);
	printf("Terminating main thread\n");
	return 0;
}
