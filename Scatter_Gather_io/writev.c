/*
in this application we write data into buffers at one call atomically
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/uio.h>
#include<sys/stat.h>
#include<string.h>


#define MAX1 5
#define MAX2 10
#define MAX3 5


int main(int argc, char *argv[])
{
	
	struct iovec iov[3];
	int fd = 0;
	int length = 0, ret = 0;
	
	
	iov[0].iov_base = "Hello";
	iov[0].iov_len = strlen("Hello");
	length += strlen("Hello");
	
	iov[1].iov_base = "1234567890";
	iov[1].iov_len = strlen("1234567890");
	length += strlen("1234567890");
	
	iov[2].iov_base = "ABCDE";
	iov[2].iov_len  = strlen("ABCDE");
	length += strlen("ABCDE");


	//open file
	
	if(argc != 2)
	{
		printf("invalid arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_WRONLY);
	if(fd == -1)
	{
		printf("Error to open file: %s\n",argv[1]);
		return -1;
	}
	
	ret = writev(fd, iov, 3);
	
	if(ret == -1)
	{
		printf("Error to writev\n");
		close(fd);
		return -1;
	}
	
	
	printf("total write bytes : %ld\n",ret+write(fd,"\n",1));
	
	close(fd);
	
	return 0;
}
