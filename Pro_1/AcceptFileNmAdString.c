/*
 Write a program which accept filename and string from user and write that string into file.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <stdlib.h>
#include<string.h	>


int main(int argc, char *argv[])
{
	int fd;
	int ret;
	
	
	if(argc != 3)
	{
		printf("Insuffiend arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_WRONLY);
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}

	ret = write(fd, argv[2], strlen(argv[2]));	
	
	if(ret == -1)
	{
		printf("Error to read file\n");
		close(fd);
		return -1;
	}

	printf("Data got written successfully : \n ");
	
	close(fd);
	
	
	return 0;
}	

