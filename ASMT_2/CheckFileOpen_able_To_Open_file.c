/*
3. Write a program which accept file name and on mode and that program check whether our
process can access that file in accepted mode or not.

input: filename Mode


*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	
	int fd;
	
	printf("File Name is: ---> : %s\n",argv[1]);
	printf("File Name is: ---> : %s\n",argv[2]);
	
	
	fd = open(argv[1], *argv[2]);
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		return -1;
	}
	
	printf("File descriptor of opened file is : %d\n",fd);
	printf("File is opened with given mode\n");
	
	close(fd);
	
	printf("File closed Successfully\n");
	printf("\n");
		
	return 0;
}
