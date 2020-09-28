/*
	accept file name from user and write into that file sum data from two buffer using one call 
	writev(fd, buff[], 2); two buffer are using to write into file with same call
	
	
*/

#include<stdio.h>
#include<sys/uio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd, ret;
	int totsize = 0;
	
	if(argc != 2)
	{
		printf("invalid arguments count\n");
		return -1;
	}
	
	fd = open(argv[1], O_WRONLY); //only for write
	
	if(fd == -1)
	{
		printf("Error to open file : %s\n",argv[1]);
		close(fd);
		return -1;	
	}
	
	printf("File opened successfully\n");
	
	/////////////////now create struct obj
	
	struct iovec iov[2];
	
	
	
	char *str1 = "Hello ";
	char *str2 = "World\n";
	ssize_t nwritten;
	
	iov[0].iov_base = str1;
	iov[0].iov_len = strlen(str1);
	
	iov[1].iov_base = str2;
	iov[1].iov_len = strlen(str2);
	
	ret = writev(fd, iov, 2); //writing 3 buffer in one call continuesly
	
	if(ret == -1)
	{
		printf("Error to writev\n");
		close(fd);
		return -1;
	}
	
	printf("Total written bytes : %d\n",ret);
	close(fd);


	return 0;
}
