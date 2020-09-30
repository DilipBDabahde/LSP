/*
	accept file name from user and read data from the file using readv(fd, struct iovec *ptr, len)
	
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/uio.h>

#define BUFFSIZE 10

int main(int argc, char *argv[])
{
	
	int fd, ret;
	char buff1[BUFFSIZE];
	char buff2[BUFFSIZE];
	
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file : %s\n",argv[1]);
		return -1;
	}
	
	printf("File opened successfully in read mode : %s\n",argv[1]);
	
	
	//one buffer created to read and its size also mention to read 
	struct iovec iov[2];	
	iov[0].iov_base = buff1; //addreess of buff arr assignto iov_base is poineter void 
	iov[0].iov_len = BUFFSIZE-1;	
	
	iov[1].iov_base = buff2;
	iov[1].iov_len = BUFFSIZE-1;

	//now using buffer to read data 
	
	ret = readv(fd, iov, 2);
	
	if(ret == -1)
	{
		printf("Error to read file  : %s\n",argv[1]);	
		close(fd);
		return -1;
	}
	
	printf("file read successfully\n");
	
	if(strlen(buff1) < BUFFSIZE && strlen(buff1) == 0 )
	{
		printf("File data is 1: %s\n",buff1);
		printf("Buff size: %ld\n",strlen(buff1));	
	}
	else
	{
		//remove unnessessary text from below printf 
		printf("File data is 1: %s\n",buff1);
		printf("File data is 2: %s\n", buff2);
		
		printf("Buff size: %ld %ld\n",strlen(buff1), strlen(buff2));	
	}
	
	close(fd);	

	return 0;
}

