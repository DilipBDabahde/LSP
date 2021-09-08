/*
WAP to dup2 demo

int dup2(int oldfd, int newfd);    

return value of dup2 is newfd | in failure return value is -1
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main()
{
	int fd;
	
	if(dup2(1, fd) == -1)
	{
		printf("Dup2 is failed\n");
		return -1;
	}
	
	printf("dup2 is successfull\n");
	
	write(fd, "dup2 is written\n", strlen("dup2 is written\n"));
	
	return 0;
}
