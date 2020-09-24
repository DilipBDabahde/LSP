/*
5. Write a program which accept file name and position from user and read 20 bytes from that position.


*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 1024

int main(int argc, char *argv[])
{
	
	int fd, ret;
	char buff[MAXSIZE];
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open %s file\n",argv[1]);
		return -1;
	}
	
	//we shifted our fd position when it first time opene it was 0 but by lseek it set to 20 read from 20ahead
	
	lseek(fd, atoi(argv[2]), SEEK_SET);
	
	ret = read(fd, buff, MAXSIZE);
	
	
	if(ret == -1)
	{
		printf("Error to read file %s\n",argv[1]);
		close(fd);
		return ret;
	}
	
	printf("Read data: \n");
	write(1, buff, ret);
	close(fd);
	

	return 0;
}

