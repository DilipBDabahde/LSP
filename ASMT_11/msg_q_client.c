/*
	in this application we create client application to demonstration concept of message queue
	
	ftok(): is use to generate a unique key.

	msgget(): either returns the message queue identifier for a newly created message 
			  queue or returns the identifiers for a queue which exists with the same key value.

	msgsnd(): Data is placed on to a message queue by calling msgsnd().

	msgrcv(): messages are retrieved from a queue.

	msgctl(): It performs various operations on a queue. Generally it is use to 
		      destroy message queue.
		      
	only one way communication
	
*/


#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdlib.h>

#define MAXSIZE 1024


struct msgData
{
	int msgtype;
	char msgbuff[MAXSIZE];
}msgInfo;


int main(int argc, char *argv[])
{
	key_t key;
	int msgid;
	int ret;
	char buff[MAXSIZE] = {'\0'};
	
	printf("size of struct : %ld\n",sizeof(msgInfo));
	
	
	//create token	
	key = ftok(".", 0); // ..    .   abc
	printf("ftok generated key is: %d\n",key);
	
	if(key == -1)
	{
		printf("error to generate ftok key\n");
		exit(-1);
	}
	
	//msg prepartion
	msgid = msgget(key, 0644);   //create msg q if not exists, if its there then open it
	if(msgid == -1)
	{
		printf("msgget failed\n");
		exit(-1);
	}	
	printf("msg identifier is: %d\n",msgid);
	
	
	
	//initialize struct members		
	//sending mgs
	ret = msgrcv(msgid,				//msg_q id which is unique 
		   &msgInfo,				//address of our struct which is initiated with values
		   sizeof(msgInfo), 		//size of our struct
		   0,						//msg to receive
		   0);						//req to read whole size of struct to kernel
	
	if(ret == -1)
	{
		printf("msgsnd failed\n");
		exit(-1);
	}
	
	printf("msg read successfully: %s\n",msgInfo.msgbuff);
	exit(EXIT_SUCCESS);
}
