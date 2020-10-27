/*
in this application create pipe and write data into pipe from parent process and read data from chilld

after creating pipe create child process
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define size 1024

int main()
{
	int fds[2];
	pid_t pid;
	int ret;
	char buff[512];
	
	
	ret = pipe(fds);
	
	if(ret == -1)
	{
		printf("Error to create pipe\n");
		exit(-1);
	}
	
	switch(fork())
	{
		case -1:
			printf("Error to create chlid process\n");
			break;
		
		case 0:
			if(close(fds[1] == -1))
			{
				printf("error to close fds\n");
				exit(-1);
			}
			

			memset(buff, 0, size);
			read(fds[0], buff, size);
			
			printf("data from pipe is: %s\n",buff);
			break;
		
		default:	//parent processs
			
			if(close(fds[0]) == -1)
			{
				printf("error to close fds\n");
				exit(-1);
			}
			
			printf("Enter string: ");
			scanf("%[^'\n']s",buff);
			
			write(fds[1], buff,strlen(buff));
			break;	
	}
	
	exit(0);
}
