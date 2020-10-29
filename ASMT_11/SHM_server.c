/*
	ServerApp
	in this application we create SHM region and attach it into our process address space
	
	in server application we write 1 to 9 digits into shared memory and client read this memory and make sum & display
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#define SHMSIZE 1024


int main(int argc, char *argv[])
{
	int shm_id;
	key_t key;
	char *shm1, *shm2;
	
	shm1 = shm2 = NULL;
	
	
	//use ftok to generate token
	
	key = ftok("..", 0);
	printf("ftok generated key is: %d\n",key);
	
	
	shm_id = shmget(key, SHMSIZE, IPC_CREAT | 0666);
	printf("SHMID is : %d\n",shm_id);
	
	shm1 = shmat(shm_id, NULL, 0);
	printf("shared memory attached at : %p\n",shm1);
	
	shm2 = shm1;
	for(int i = 1; i <= 9; i++)
	{
			*shm2 = i;
			shm2 = sizeof(int)+shm2;
	}
	
	*shm2 = '\0';
	
	while(*shm1 != 'x')
	{
		sleep(1);
	}
	
	shmdt(shm1);
	printf("client read data sent by server\n");
	

	exit(0);
}

