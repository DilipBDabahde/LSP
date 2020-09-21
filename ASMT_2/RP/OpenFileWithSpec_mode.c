/*
2. Write a program which accept file name and mode from user and then open that file in	specified mode.

input: Demo.c read


*/

#include<stdio.h>
#include<unistd.h> //open call
#include<fcntl.h> // to allocate file opening mode
#include<string.h> //to compare string


int main(int argc, char *argv[])
{
	int mode, fd;
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	//fixing mode 
	if(strcmp(argv[2], "read") == 0)
	{
		mode = O_RDONLY;
	}
	else if(strcmp(argv[2], "write") == 0)
	{
		mode = O_WRONLY;
	}
	else if(strcmp(argv[2], "append") == 0)
	{
		mode = O_APPEND;
	}
	else if(strcmp(argv[2], "read+write") == 0)
	{
		mode = O_RDWR;
	}
	else
	{
		printf("Unknow Mode\n");
		return -1;
	}

	
	fd = open(argv[1], mode);
	
	if(fd == -1)
	{
		printf("Error : to open file\n");
		close(fd);
		return -1;	
	}

	printf("File opened successfully with given mode\n");
	
	close(fd);

	return 0;
}
