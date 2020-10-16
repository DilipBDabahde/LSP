/*
	demonstrion of thread syncronization 
*/


#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int bal = 500;

pthread_mutex_t lock;


void *fun(void *ptr)
{
	pthread_mutex_lock(&lock);		//syncronization
	
	for(int i = 1; i <= (int)ptr; i++)
	{
		printf("fun : %d\n",i);
		
	}
	pthread_mutex_unlock(&lock);
	
	pthread_exit((int)ptr);
}


void *gun(void *ptr)
{
	pthread_mutex_lock(&lock);		//syncronization
	
	for(int i = 1; i <= (int)ptr; i++)
	{
		printf("gun : %d\n",i);
		
	}
	pthread_mutex_unlock(&lock);
	
	pthread_exit((int)ptr);
}



int main()
{


	pthread_t t1, t2;
	int ret1, ret2, status1, status2;
	int iNo1 = 100, iNo2 = 100;
	
	ret1 = pthread_create(&t1, NULL, (void*)fun, (void*)iNo1);
	ret2 = pthread_create(&t2, NULL, (void*)gun, (void*)iNo2);	
		
	pthread_join(t1, &status1);
 	pthread_join(t2, &status2);
	
	printf("t1 withdrawal successfully : %d\n",(int)status1);	
	printf("t2 withdrawal successfully  : %d\n",(int)status2);	
	
	return 0;
}
