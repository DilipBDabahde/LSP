/*
1. Write a program which creates two process as reader and writer and that processess
   should communicate with each other using FIFO.
   
  	Client_App
  	
  	in this application we open created file and read msg from this file and display
   
   
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>

#define MAXSIZE 1024


int main()
{

	int fd, ret;
	char buff[MAXSIZE] = {'\0'};
	char *path = "/tmp/named_pipe.txt";  //char pointer's array
	
	//already created file is opening in given path
	fd = open(path, O_RDONLY);
	
	if(fd == -1)
	{
		perror("open");
		exit(-1);
	}
	
	
	while((ret = read(fd, buff, sizeof(buff))) > 0)		
	{
		write(STDOUT_FILENO, buff, ret);	
	}
	close(fd);
	
	printf("data sent by parent process successfully\n");
	
	
	exit(0);
}
