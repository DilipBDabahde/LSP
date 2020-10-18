#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMSZ 30

int main()
{

	int shmid;
	key_t key;
	char *shm, *s;
	
	printf("Demo of IPC using Shared Memory\n");
	
	printf("Client is running...\n");
	
	key = ftok(".",'a');
	
	shmid  = shmget(key, SHMSZ, 0666);
	
	shm = shmat(shmid, NULL, 0);
	
	printf("Data is received from server\n");
	
	for(s = shm; *s != '\0'; s++)		//reading data which is added by server into shared memory
	{
		printf("%c",*s);	
	}
	
	*shm = '*';  //change first character of shared memory  means chhild process write to shared memory
	
	printf("\nTerminating the client\n");

	exit(0);
}
