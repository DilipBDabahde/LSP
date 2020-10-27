//named pipe server application

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>


int main()
{
	int fd, ret;  //for file
	int pipFDs[2] = {0, 1};  // 0  to read   // 1 to write
	char *fifo = "/tmp/fifo";  // named  pipe name address assigne to pointer
	char msg[] = "World is beautiful";
	
	ret = pipe(pipFDs);
	
	printf("Demo of IPC using named PIPE\n");
	printf("Server is running\n");
	
	
	if(ret < 0)
	{
		perror("pipe failed");
		exit(1);
	}
		
	//creating named pipe / fifo	
	mkfifo(fifo, 0666);
	
	fd = open(fifo, O_WRONLY); //opening named pipe to write msg
	
	if(fd == -1)
	{
		perror("open");
		close(fd);
		exit(1);
	}
	
	ret  = write(fd, msg, strlen(msg));
	
	if(ret == -1)
	{
		perror("write");
		close(fd);
		exit(1);
	}
	
	printf("Message is writter to named pipe successfully\n");
	
	close(fd);

	return 0;
}

