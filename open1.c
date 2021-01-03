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
#include<stdlib.h>


#define BUFSIZE 512

int main(int argc, char *argv[])
{
	int fd = 0, ret =0, i = 0;
	char buff[BUFSIZE] = {'\0'};
	
	if(argc != 2)
	{
		printf("invalid arguments\n");
		return -1;
	}
	
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("open fails\n");
		return -1;
	}
	
	
	
	printf("Enter 1 to read\n");
	printf("Enter 2 to terminate process\n");
	scanf("%d",&i);
	
	if(i == 1)
	{
		while((ret = read(fd, buff, BUFSIZE)) > 0)
		{
			if(ret == -1)
			{
				printf("error to read data\n");
				return -1;
			}
			
			if(i == 1)
			{
				write(1, "Read data is: ", strlen("Read data is: "));
				i++;
			}
			
			if(write(1, buff, ret) != ret)
			{
				write(1, "write fails\n", strlen("write fails\n"));
				return -1;
			}		
		}
	}
	else if(i == 2)
	{
		printf("process %d terminated successfully\n",getpid());
		exit(0);
	}	
	else
	{
		printf("invalid input\n");
	}
	
	close(fd);
	
	
	return 0;
}
