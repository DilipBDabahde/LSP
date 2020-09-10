#include<stdio.h>
#include<fcntl.h>


int main()
{
	
	int fd;
	
	fd = open("div.txt", O_WRONLY | O_CREAT | O_APPEND);
	
	if(fd == -1)
	{
		printf("Not able to open file\n");
	}
	else
	{
		printf("File is opened with fd %d\n",fd);
	}

	
	return 0;
}
