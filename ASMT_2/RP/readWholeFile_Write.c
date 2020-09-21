/*
6+ Write a program which accept file name from user and read whole file and write  
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 128

int main(int argc, char *argv[])
{
	
	int fd, ret;
	char buff[MAXSIZE];
	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		return -1;
	}
	
	printf("File opened successfully\n");
	
	while( (ret = read(fd, buff, MAXSIZE))  >  0 )  // till not get it reads data from buff
	{
		if(write(1,buff,ret) != ret)
		{}
	}
		
	close(fd);
	
	return 0;
}
