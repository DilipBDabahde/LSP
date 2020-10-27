///Application program for Named pipe - client Application

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#define BUFFSIZE 1024

int main()
{
	
	int fd;
	char *fifo = "/tmp/fifo";
	char buff[BUFFSIZE] = {'\0'};
	
	printf("Demo of IPC using named pipe\n");
	
	printf("Client Process is running\n");
	
	//opening file
	fd = open(fifo, O_RDONLY);
	
	//reading opened file data
	read(fd, buff, BUFFSIZE);
	
	printf("Recieved data is: %s\n",buff);
	
	//closing opened file
	close(fd);
	
	return 0;
}

