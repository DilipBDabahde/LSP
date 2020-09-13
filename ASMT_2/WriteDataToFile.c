/*
7. Write a program which accept file name from user and write string in that file.

input: mydemo.txt
	   
	   char buff[] = "We are learning Linux System Programming Step By Step."
	   
	   
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	int fd;
	int ret = 0;
	char buff[] = "We are learning Linux System Programming Step By Step.";
	
	fd = open(argv[1], O_RDWR | O_APPEND);
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File opened successfully and fd is %d\n",fd);
	
	ret = write(fd, buff, sizeof(buff));
	
	if(ret == -1)
	{
		printf("Error : Unable to write into file\n");
		close(fd);
		return  -1;
	}
	
	printf("--> %s <--Data written successfully\n",buff);
	
	
	close(fd);
	
	return 0;

}
