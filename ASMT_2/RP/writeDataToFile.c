/*
7. Write a program which accept file name from user and write string in that file.

to write data into file we must take care of writing into file bcs our previous file data may be lost

so to avoid this we must open file in append mode to avoid losing of file existing data

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[])
{

	int fd, ret;
	char arr[] = "World is beautiful";
	int mode = O_WRONLY |O_APPEND;   // to avoid existing data lost 
	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}

	fd = open(argv[1], mode );
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File is opened successfully\n");
	
	ret = write(fd, arr, strlen(arr));
	
	if(ret == -1)
	{
		printf("Error to write data into file\n");
		close(fd);
		return -1;
	}
	
	printf("Data is written successfully\n");
	
	close(fd);
		
	return 0;
}

