/*
	display existing file size
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>



int main(int argc, char *argv[])
{
	int fd = 0, ret = 0;
	
	if(argc != 2)
	{
		printf("invalid arguments count\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("open fails\n");
		return -1;
	}
	
	ret = lseek(fd, 0, SEEK_END);
	
	printf("file size is : %ld\n", (long)ret);
	
	close(fd);
	
	return 0;
}
