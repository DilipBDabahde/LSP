//application program of messgae queue
//server application

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>
#include<stdlib.h>

#define BUFFSIZE 512

struct msg_data					//struct to create message queue
{	
	long int msg_type;
	char msg_buff[BUFFSIZE];
};

int main()
{
	int running = 1, msgid;
	struct msg_data obj;		//obj is user defined datatype variable
	char buffer[BUFFSIZE];
	
	printf("Demonstration of IPC using message queue\n");
	
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);		//call to get msgid
	if(msgid == -1)
	{
		printf("failed to create\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Message queue is created successfully\n");
	printf("pid: %d\n",getpid());
	while(running)
	{	
		printf("Enter some message: ");
		fgets(buffer, BUFFSIZE, stdin);
		obj.msg_type = 1;
		strcpy(obj.msg_buff, buffer);
		
		if(msgsnd(msgid, (void*)&obj, BUFFSIZE, 0)== -1)
		{
			printf("msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		
		if(strncmp(buffer, "end", strlen("end")) == 0)
		{
			running = 0;
		}
	}
	
	printf("Terminating the server process\n");
	exit(EXIT_SUCCESS);	
}
