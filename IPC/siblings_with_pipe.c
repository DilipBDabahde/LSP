/*
	in this application we create pipe in parent process
	then after sucessfully created pipe
	we create two chilld process
	and one child write data and another child read data
	till both child terminate parents wait
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

#define size 1024

int main()
{
	int ret, status2, status1, fds[2];
	pid_t pid1, pid2;
	char buff[size] = {'\0'};

	ret = pipe(fds);
	
	if(ret == -1)
	{
		printf("error to create pipe\n");
		exit(-1);
	}
	
	if( (pid1 = fork()) == -1 &&  (pid2 = fork())  == -1)
	{
		printf("errror to create two child processes\n");
		exit(-1);	
	}
	
	if(pid1 == 0)	//child 1 process area
	{
	
		if(close(fds[0]) == -1)
		{
			printf("error to write end\n");
			exit(-1);
		}
		
		printf("Enter string : ");
		scanf("%[^'\n']s",buff);
		
		ret = write(fds[1], buff, strlen(buff));
		printf("total bytes write by child 1 : %d\n", ret);
		close(fds[1]);
		
		exit(0);
	}
	
	if(pid2 == 0) //child 2 process area
	{
		if(close(fds[1]) == -1)
		{
			printf("error to close read fds\n");
			exit(-1);
		}
		
		ret = read(fds[0], buff, size);
		
		printf("total bytes read  by child 2: %d\n",ret);
		printf("read data by child 2 is: %s\n",buff);
		
		close(fds[0]);		
		
		exit(0);
	}
	else	//parent area
	{
		
		pid1 = waitpid(pid1, &status1, CLD_EXITED);
		pid2 = waitpid(pid2, &status2, CLD_EXITED);
		
		printf("pid1 status  : %d\n",status1);
		printf("pid2 status  : %d\n",status2);
	
	}
	

	exit(0);
}
