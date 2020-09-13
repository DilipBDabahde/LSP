/*
6. Write a program which accept file name from user and read whole file.

input: mydemo.txt

	
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	
	int fd;
	char buff[1024];
	int ret = 0;
	
	
	fd = open(argv[1], O_RDONLY); 
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File opened Successfully\n");
	
	ret = read(fd, buff, sizeof(buff));
	
	
	if(ret == -1)
	{
		printf("Error : Unable to read file\n");
		close(fd);
		return -1;
	}
	
	printf("Data read successfully from file\nDATA : %s\n",buff);
	
	close(fd);
	close(ret);

	return 0;
}
