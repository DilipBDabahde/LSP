/*
	this is shared memory application for client and this application read data from shared memory and perform some 
	operation and display read data from shared memory
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#define SHMSIZE 1024

int main()
{

	int shmid;
	int isum = 0;
	key_t key;
	char *shm1, *shm2;
		
	shm1 = shm2 = NULL;	//set both pointer to NULL
	
	key = ftok("..",0); //creating key for shmget	
	printf("ftok generated key is: %d\n",key);
	
	
	shmid = shmget(key, SHMSIZE,  0666);	//get shared memory id
	printf("shm id is : %d\n",shmid);
	
	
	shm1 = shmat(shmid, NULL, 0);				//attaching SHM in process address space
	printf("shared memory attached in process address : %p\n",shm1);
	

	shm2 = shm1;
	
	while(*shm2 != '\0')
	{
		printf("%d ",*shm2);
		isum += *shm2;
		shm2 = sizeof(int) + shm2;
	}
	

	printf("\nClient read data from shared memory\n");
	printf("Sum of nums is: %d\n",isum);

	*shm1  = 'x';
	
	printf("client says by to server\n");
	
	exit(EXIT_SUCCESS);
}
