/*
2. Write a program which accept file name and mode from user and then open that file in
specified mode

*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	
	int fd;
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File Opened in O_RDONLY mode fd is : %d\n",fd);
	
	close(fd);
	printf("\n");
	
	
	return 0;
}
