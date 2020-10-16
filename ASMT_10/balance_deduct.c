#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int bal = 500;

pthread_mutex_t lock;


void *deduct(void *ptr)
{
	pthread_mutex_lock(&lock);		//syncronization
	
	if(bal < (int)ptr)
	{
		pthread_exit((int)-1);
	}

	bal = bal - (int)ptr;
	
	pthread_mutex_unlock(&lock);
	
	pthread_exit((int)ptr);
}



int main()
{


	pthread_t t1, t2;
	int ret1, ret2, status1, status2;
	int iNo1 = 200, iNo2 = 400;
	
	ret1 = pthread_create(&t1, NULL, (void*)deduct, (void*)iNo1);
	ret2 = pthread_create(&t2, NULL, (void*)deduct, (void*)iNo2);
	
	if(ret1 != 0)
	{
		printf("Error to create thread 1\n");
		return -1;
	}
		
	pthread_join(t1, &status1);
	
	if((int)status1 == -1)
	{
		printf("insufficient bal for t1\n");
		return -1;
	}
	
	printf("t1 withdrawal successfully : %d\n",(int)status1);	
	
	/////////////////////////////////////////////////////////////////////////////////
	
	

	
	if(ret2 != 0)
	{
		printf("Error to create thread 2\n");
		return -1;
	}
	
	if((int)status2 == -1)
	{
		printf("insufficient bal for t2\n");
		return -1;
	}

	pthread_join(t2, &status2);

	printf("t2 withdrawal successfully  : %d\n",(int)status2);	
	
	return 0;
}
