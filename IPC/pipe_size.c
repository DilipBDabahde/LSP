#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
	int fds[2];
	
	int ret;
	
	ret = pipe(fds);
	
	if(ret == -1)
	{
		printf("error to create pipe\n");
		exit(-1);
	}
	
	
	printf("pipe size : %ld\n",fpathconf(fds[0], _PC_PIPE_BUF));
	
	return 0;
}
