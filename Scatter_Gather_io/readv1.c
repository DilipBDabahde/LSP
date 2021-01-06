/*
in this application we use concept of readv using 3 diff array with set to '\0' 
then we open a file and read data from opned file using fd of the file

*/

#include<stdio.h>
#include<sys/uio.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

#define MAX1 5
#define MAX2 10
#define MAX3 5


//entry point function
int main(int argc, char *argv[])
{
	
	//create buffers
	struct iovec iov[4];
	int length = 0;
	int fd = 0;
	
	//forms 3 arrays	
	char arr[MAX1+1] = {'\0'};
	char brr[MAX2+1] = {'\0'};
	char crr[MAX3+1] = {'\0'};
	
	
	//now specify base adddress and lenght of buffers
	
	iov[0].iov_base = arr;
	iov[0].iov_len  = MAX1;
	length += MAX1;
	
	iov[1].iov_base = brr;
	iov[1].iov_len  = MAX2;
	length += MAX2;
	
	iov[2].iov_base = crr;
	iov[2].iov_len  = MAX3;
	length += MAX3;
	
		
	printf("total lenght is: %d\n", length);
	
	if(argc != 2)
	{
		printf("invalid argument count\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file: %s\n",argv[1]);
		return -1;
	}
	
	if(readv(fd, iov,3) == -1)
	{
		printf("Error to readv\n");
		close(fd);
		return -1;
	}
	
	printf("readv successful\n");

	printf("first buffer size:%d : %s\n",MAX1, arr);
	printf("second buffer size:%d: %s\n",MAX2, brr);
	printf("second buffer size:%d: %s\n",MAX3, crr);
		
	exit(EXIT_SUCCESS);
}
