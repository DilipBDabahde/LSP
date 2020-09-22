/*
4. Write a program which accept two file names from user and copy the contents of an existing file into newly created file.

*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE	128

int main(int argc, char *argv[])
{
	int fd1, fd2, ret1, ret2;
	char buff[MAXSIZE];
	
	if(argc != 3)
	{
		printf("insufficient arguments\n");
		return -1;	
	}

	fd1 = open(argv[1], O_RDONLY);
	
	if(fd1 == -1)
	{
		printf("Error to open file\n");
		close(fd1);
		return -1;
	}
	
	fd2 = creat(argv[2], 0777);
	
	if(fd2 == -1)
	{
		printf("Error to create file\n");
		close(fd1);
		close(fd2);
		return -1;
	}
	
	fd2 = open(argv[2], O_WRONLY | O_APPEND);
	
	if(fd2 == -1)
	{
		printf("Error to open new created file\n");
		close(fd1);
		close(fd2);
		return -1;
	}
	
	while( (ret1 = read(fd1, buff, sizeof(buff))) > 0)
	{
		if( (ret2 = write(fd2, buff, ret1) != ret1) )
		{}
	}
	
	if(ret1 == -1)
	{
		printf("Error to read file\n");
		close(fd1);
		close(fd2);
		return -1;
	}
	
	if(ret2 == -1)
	{
		printf("Error to write into file\n");
		close(fd1);
		close(fd2);
		return -1;
	}
	
	printf("Data is copyied successfully to new file\n");
	
	close(fd1);
	close(fd2);
	
	return 0;
}
