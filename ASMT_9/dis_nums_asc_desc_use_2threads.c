/*
2. Write a program which creates two thread , first thread print numbers 
   from 1 to 500 & other thread print the numbers from 500 to 1.
	
	$gcc myfile.c -o myexe -lpthread -w
	$./myexe
*/

#include<stdio.h>
#include<pthread.h>


void *First(void *ptr)
{
	for(int i = 1; i <= (int)ptr; i++)
	{
			printf("First : %d\n",i);
	}	
	pthread_exit(NULL);
}




void *Second(void *ptr)
{
	for(int i = (int)ptr; i >= 1;  i--)
	{
			printf("Second : %d\n",i);
	}	
	pthread_exit(NULL);
}




int main()   //main thread of exe
{

	pthread_t t1, t2;
	int ret1, ret2;
	int iNo1 = 100, iNo2 = 100;
	int status1, status2;
	
	
	//create first thread
	
	ret1 = pthread_create(&t1, NULL, (void*)First, (void*)iNo1);
	
	if(ret1 != 0)
	{
		printf("Error to create thread 1\n");
		return -1;
	}
	
	ret2 = pthread_create(&t2, NULL, (void*)Second, (void*)iNo2);
	
	if(ret2 != 0)
	{
		printf("Error to create thread 2\n");
		return -1;
	}
	
	
	//wait till thread gets exits and return status
	
	pthread_join(t1, &status1);
	pthread_join(t2, &status2);
	
	printf("Status of t1 is : %d\n",status1);
	printf("Status of t2 is : %d\n",status2);
	printf("Terminating main thread\n");
	return 0;
}
