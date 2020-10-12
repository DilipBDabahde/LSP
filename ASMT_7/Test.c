
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{

	pid_t pid;
	int fd, ret;
	
	char buff[128] = {'\0'};
	
	
	pid = fork();
	
	if(pid == 0)
	{
		printf("child pid: %d\n",getpid());
		
		fd = open(argv[1],O_RDONLY);
		
		if(fd == -1)
		{
			printf("Error to open file\n");
			exit(-1);
		}
		
		while((ret = read(fd, buff, sizeof(buff))) != 0)
		{
			write(1, buff, ret);
		}
		close(fd);
		
		
	}
	else
	{
		printf("parent pid : %d\n",getpid());
	}
	
	
	exit(0);
}
