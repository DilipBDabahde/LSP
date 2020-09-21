/*
3. Write a program which accept file name and on mode and that program check whether our process can access that file in accepted mode or not.
s
input: demo.c  read/write/execute

if our process is having permission to access that file then it will access to that file else return -1 on
success return 0

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


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
		mode = R_OK;
	}
	else if(strcmp(argv[2], "write") == 0)
	{
		mode = W_OK;
	}
	else if(strcmp(argv[2], "execute") == 0)
	{
		mode = X_OK;
	}
	else
	{
		printf("Unknow Permission\n");
		return -1;
	}

	fd = access(argv[1], mode);
	
	if(fd == -1)
	{
		printf("Error to accesss file with given mode\n");
		close(fd);
		return -1;
	}
	
	printf("Our process can access this file with given mode\n");

	return 0;
}
