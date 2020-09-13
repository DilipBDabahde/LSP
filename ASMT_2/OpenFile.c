/*
1. Write a program which accept file name from user and open that file.

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	
	int fd;
	
	fd = open(argv[1], O_RDWR);
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File is opened successfully fd is %d\n",fd);
	
	printf("\n");

	return 0;
}
