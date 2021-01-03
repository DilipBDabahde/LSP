/*ref open2.c 
in this application we open file to read
and into another application we open file to write 
we do it on two terminal tal

on first open for read wait for second terminal tab operation in second tab we write data then again open first tab 
of terminal and then read data

this all takes place in two seperate processes
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BUFSIZE 512

int main(int argc, char *argv[])
{
	int fd = 0, ret = 0;
	char buff[BUFSIZE] = {"c Programming\n"};
	
	if(argc != 2)
	{
		printf("invalid input\n");
		return -1;
	}

	fd = open(argv[1], O_WRONLY | O_APPEND);
	if(fd == -1)
	{
		printf("open fails\n");
		return -1;
	}
	
	printf("%s file open with fd %d\n",argv[1],fd);
	
	ret = write(fd, buff, strlen(buff));
	if(ret == -1)
	{
		printf("error to write\n");
		return 0;
	}
	
	printf("data written successfully: %s\n",buff);
	
	close(fd);

	return 0;
}
