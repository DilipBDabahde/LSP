/*
2. Write a program which accept file name from user which contains information of employee
   we have to read all contents of that file.
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


#define MAXSIZE 512


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
	
	printf("%s file opened successfully\n",argv[1]);
	
	
	ret = read(fd, buff,MAXSIZE);
	
	if(ret == -1)
	{
		printf("Error to read data from \"%s\" file\n",argv[1]);
		return -1;
	}
	
	printf("Employee data read successfully\n\n%s\n",buff);
	
	close(fd);

	return 0;
}
