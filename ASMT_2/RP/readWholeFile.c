/*
6+ Write a program which accept file name from user and read whole file.

  
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 1024



int main(int argc, char *argv[])
{
	
	int fd, ret;
	char arr[MAXSIZE];
	
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
	
	ret = read(fd, arr, MAXSIZE);
	
	if(ret == -1)
	{
		printf("Error to read file\n");
		#undef MAXSIZE
		return -1;
	}
	
	printf("Data read successfully :\n%s\n",arr);

	close(fd);
	
	return 0;
}
