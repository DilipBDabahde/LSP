/*
	creaet pipe and child process by parent 
	then parent wait till chlid terminate 
	in child process child write data to pipe and 
	then after child termination parent read data from pipe and display
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

#define size 1024

int main()
{
	int ret, fds[2], status = 0;
	pid_t pid;
	char buff[size] = {'\0'};
	
	ret = pipe(fds);
	
	if(ret == -1)
	{
		printf("error to create pipe\n");
		exit(-1);
	}
	
	pid = fork();
	
	if(pid == -1)	
	{
		printf("error to create child process\n");
		exit(-1);
	}
	
	if(pid == 0)//child process area
	{
		
		if(close(fds[0]) ==  -1)
		{
			printf("error to close read fds\n");
			exit(-1);
		}
		
		printf("enter string: ");
		scanf("%[^'\n']s",buff);
		
		ret = write(fds[1], buff, strlen(buff));
		printf("total bytes write by child is : %d\n",ret);
		
		close(fds[1]);
		exit(0);//	end of child process	
	}
	else	//parent process area
	{
		if(close(fds[1]) == -1)
		{
			printf("error to close write fds\n");
			exit(-1);
		}
		
		pid = wait(&status);
		
		printf("status of child process : %d\n",status);
		
		ret = read(fds[0], buff, size);
		printf("total bytes read by parent: %d : data : %s\n",ret, buff);
		
		close(fds[0]);
	}
	
	exit(0);
}
