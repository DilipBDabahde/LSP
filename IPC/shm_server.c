#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

#define SHMSZ 30


int main()
{

	char c;
	int shmid;
	char *shm, *s1, *s2;
	
	printf("Demo of IPC using Shared Memory\n");
	
	key_t key = ftok(".",'a');
	
	shmid = shmget(key, SHMSZ, IPC_CREAT | 0666); 
	
	shm = shmat(shmid, NULL, 0);  //return add of shared memory
	
	s1 = s2 = shm;  //assign addrsss to same type ptr
	
	for(c = 'a'; c <= 'z'; c++)
	{
		*s1 = c;	//store char on allocated memory
		s1++;		
	}

	printf("Data is written in Shared Memory\n");
	
	*s1 = '\0';

	//Wait until other process changes the first character of our memory to '*' 
	//indicating that it has read what we put there.
	
	while (*shm != '*')
	{
		sleep(1);
	}
	
	printf("\nData is Successfully fetched by client\n");
	printf("Upated data is: %s\n",s2);
	printf("Terminating server\n");
	exit(0);


}
