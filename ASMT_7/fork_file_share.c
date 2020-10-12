/*
	demonstration of file fd shraing between parent to child process
	
	accept file name from user and open it into process and share its fd with newly created process
	
	
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	int ret, fd;
	char buff[] = "Child write\n";
	char buff2[] = "Parent write\n";
	
	fd = open(argv[1], O_RDWR | O_APPEND);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		return -1;
	}
	
	printf("fd is  : %d\n",fd);
	
	
	
	ret = fork();
	
	if(ret == 0)
	{
		write(fd, buff, sizeof(buff));	
		printf("fork created new pid: %d\n",getpid());
		printf("fork's parent id: %d\n",getppid());
		printf("value of ret: %d\n",ret);
	}
	else
	{
		write(fd, buff2, sizeof(buff2));
		printf("running exe pid: %d\n",getpid());
		printf("parent of exe (terminal) pid: %d\n",getppid());
		printf("fork created pid return to exe which is parent of fork created proc : %d\n",ret);
	}
	
	return 0;
}
