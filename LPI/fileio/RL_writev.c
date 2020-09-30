/*
accept file name from user and and write data into file after successfull open
from multiple buffer using writev(fd, constr struct iovec *iov, len);  using on system call

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/uio.h>
#include<stdio_ext.h>

#define BUFFSIZE 512


int main(int argc, char *argv[])
{
	int fd, ret;
	char arr[BUFFSIZE];
	char brr[BUFFSIZE];  //accept data for thesee to buffer
	
	if(argc != 2)
	{
		printf("invalid input argumets\n");
		return -1;
	}
	
	fd = open(argv[1], O_WRONLY);  //opening file to write data
	
	if(fd == -1) // fail to open file
	{
		printf("Unable to open file: %s\n",argv[1]);
		return -1;
	}
	
	printf("File opened successfully \n");
	///////////////////////////////////////fiiling buffers ///////////////////////////////////
	
	printf("Enter first buffer string: ");
	scanf("%[^'\n']s",arr);
	
	__fpurge(stdin);
	
	printf("Enter Second buffer String: ");
	scanf("%[^'\n']s",brr);
	
	
	///////////////////// now set buffers struct memeber /////////////////////////////////
	
	struct iovec iov[3];    //two obj 2 created
	
	iov[0].iov_base = arr;
	iov[0].iov_len  = strlen(arr);
	
	char newline[] = "\nNew buffer\n";
	
	iov[1].iov_base = newline;
	iov[1].iov_len = strlen(newline);
	
	iov[2].iov_base = brr;
	iov[2].iov_len = strlen(brr);	
	
	
	///////////////////// write data to accepted file name from buffers ////////////////////////
	
	ret = writev(fd, iov, 3);  //opned file fd,  void *ptr = 3 addresss , len of each address to allcated void ptr
	
	if(ret == -1)	
	{
		printf("Error to write into file : %s\n",argv[1]);
		close(fd);
		return -1;
	}
	
	printf("buffers data written successfull to : %s \n",argv[1]);
	printf("Total bytes read : %d\n",ret);
	close(fd);
	


	return 0;
}
