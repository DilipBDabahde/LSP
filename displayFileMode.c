/*
 accept file opening mode and display
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[])
{	
	int mode;
	
	if(strcmp(argv[1], "read") == 0)
	{
		mode = O_RDONLY;
	}
	else if(strcmp(argv[1], "read write") == 0)
	{
		mode = O_RDWR;
	}
	else if(strcmp(argv[1], "write") == 0)
	{
		mode = O_WRONLY;
	}
	else if(strcmp(argv[1], "append") == 0)
	{
		mode = O_WRONLY | O_APPEND;
	}
	else
	{
		printf("Unknown mode\n");
	}
	
	printf("mode is %d\n",mode);
	
	return 0;
}	

