//client application

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
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
	printf("Demonstration of IPC using Message Queue\n");
	printf("Client process is running\n");
	
	int running = 1;
	int msgid;
	struct msg_data obj;
	long int msg_to_rcv = 0;
	
	msgid = msgget((key_t)1234, 0666);
	
	printf("Fetching the message from message queue\n");
	
	while(running)
	{
		msgrcv(msgid, (void*)&obj, BUFFSIZE, msg_to_rcv, 0);
		
		printf("Received message is: %s",obj.msg_buff);
		
		if(strncmp(obj.msg_buff, "end", 3) == 0)
		{
			running = 0;
		}	
	}
	
	printf("Terminating the client process\n");

	exit(EXIT_SUCCESS);	
}
