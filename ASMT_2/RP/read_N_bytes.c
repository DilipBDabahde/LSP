/*
5. Write a program which accept file name and number of bytes from user and read that number of bytes from file.

input: demo.txt  10	
						our program will 10bytes of data from given file
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char *p  = NULL;
	int fd, ret;
	
	
	if(argc != 3)
	{
		printf("insufficient arguments\n");
		return -1;
	}

	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File opened successfully\n");
	
	p = (char*)malloc(sizeof(char)*atoi(argv[2]));
	
	if(p == NULL)
	{
		printf("Error to allocation memeory\n");
		close(fd);
		return -1;
	}
	
	ret = read(fd, p, atoi(argv[2]));
	
	if(ret == -1)
	{
		printf("Error to read data from file\n");
		close(fd);
		free(p);
		return -1;	
	}
	
	printf("data read successfully: %s\n",p);
	
	free(p);
	close(fd);
	
	return 0;
}
