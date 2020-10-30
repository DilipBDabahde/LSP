/*
1. Write a program which creates two process as reader and writer and that processess
   should communicate with each other using FIFO.
   
   Server_App
   
   Fifo is also known as named pipe which gets exists in file system unlike pipe
   file type mode is : fifo
   we can use cmd  to create fifo type file: mkfifo FifoFileName
   
   we have to open file writer process then reader process   
   
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
	
	int fd,ret;
	char buff[MAXSIZE] = {'\0'};
	char *path = "/tmp/named_pipe.txt";  
	
	mkfifo(path,		//pass file name is first argument
		  0644);		//fifo accesss permission
	
	
	fd = open(path, O_WRONLY);
	
	if(fd == -1)
	{
		perror("open");
		exit(-1);
	}
	
	printf("Enter string: ");
	fgets(buff,sizeof(buff), stdin);
	fflush(stdout);
	ret = write(fd, buff, strlen(buff));
	close(fd);
	
	if(ret == -1)
	{
		perror("write");
		exit(-1);
	}

	printf("data read by child process successfully\n");
	
	exit(0);
}
