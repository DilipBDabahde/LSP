/*
	accept file with from user and read its data completely with no-pause using
	
	readv(fd, struct iovec *iov_base, iov_len) 
	
	int this case data gets read atomically it mean continues read from offset 0 to EOF with not break
	
	in this case by using single system call data gets read in multiple buffers / set of buffers
	 
	read or write data  into multiple buffers
	
	struct iovec {
	void *iov_base;	//generic pointer
	size_t iov_len;  //no of object of struct
	};
	
	filedata.txt      			<-------- input file
				ABCDE12345
				
				
	output: 
	Total bytes read: 10
	successfully read buff 1 : ABCDE
	successfully read buff 2 : 12345

	
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/uio.h>
#include<string.h>

#define MAXSIZE 6

int main(int argc, char *argv[])
{
	int fd, ret;
		
	if(argc != 2)
	{
		printf("invalid input\n");
		return -1;
	}
	
	//
	struct iovec iov[2];  //obj created   2
	
	char arr[MAXSIZE] = {'\0'};
	iov[0].iov_base = arr;
	iov[0].iov_len = MAXSIZE-1;
	
	char brr[MAXSIZE] = {'\0'};
	iov[1].iov_base = brr;
	iov[1].iov_len = MAXSIZE-1;
		
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("error to open file\n");
		close(fd);
		return -1;
	}
	
	ret = readv(fd, iov ,2);  //sizeof(iov) * 2
	
	if(ret == -1)
	{
		printf("Error to readv \n");
		close(fd);
		return -1;
	}
	
	printf("Total bytes read: %d\n",ret);
	printf("successfully read buff 1 : %s\n",arr);
	printf("successfully read buff 2 : %s\n",brr);
	
	close(fd);
	
	
	return 0;

}
