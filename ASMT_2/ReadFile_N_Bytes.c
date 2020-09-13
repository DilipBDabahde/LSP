/*
5. Write a program which accept file name and number of bytes from user and read that number of bytes from file.

input: mydemo.txt   10bytes								 FileData
		|________________________________________________> today is first day in school, i got friends in school
														   i play with friends and study too.
		
		10bytes

output: today is f														
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	
	
	int fd;
	int ret = 0;
	
	char buff[10]; //size taken from user <----------------- make it dynamic
	
	printf("Filename is: %s\n",argv[1]);
	printf("No. of bytes to read : %ld\n", sizeof(buff));
	printf("%d\n",*argv[2]);
		
	
	fd = open(argv[1], O_RDONLY);
	
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File is opened successfully\n");
	
	
	ret = read(fd, buff, sizeof(buff));
	
	if(ret == -1)
	{
		printf("Error : Unable to read file\n");
		close(fd);
		return -1;
	}
	
	printf("File read successfully\n");
	printf("\nfrom %s file %ld-bytes read as : ->> : %s ",argv[1], sizeof(buff), buff);
	
	close(fd);
	printf("\n");

	return 0;
}
