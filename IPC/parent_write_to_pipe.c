/*
	in this application parent create pipe and write data to pipe and that data is read by child process
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define size 1024

int main()
{

	int ret, fds[2];
	pid_t pid;
	char buff[size] = {'\0'};
	
	
	ret = pipe(fds);
	
	if(ret == -1)
	{
		printf("error to create pipe\n");
		exit(-1);
	}
	
	pid = fork(); //creating chd process
	
	if(pid == -1)
	{
		printf("error to create child process\n");
		exit(-1);
	}
	
	if(pid == 0)
	{
		if(close(fds[1]) == -1)
		{
			printf("closing write end errror\n");
			exit(-1);
		}
		
		ret = read(fds[0], buff, size);
		
		printf("total read bytes to pipe is:  %d : data:  %s\n",ret, buff);
		
		close(fds[0]);	
	}
	else
	{
		if(close(fds[0]) == -1)	
		{
			printf("closing read end error\n");
			exit(-1);
		}
		
		printf("Enter data: ");
		scanf("%[^'\n']s",buff);
		
		ret = write(fds[1], buff, strlen(buff));
		
		printf("total write bytes to pipe is: %d\n",ret);
		
		close(fds[1]);	
	}

	
	exit(0);
}
