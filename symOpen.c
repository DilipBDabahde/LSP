/*
in this applciation we try to open symbolic link
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFSIZE 512

int main(int argc, char *argv[])
{
	int fd = 0, ret = 0;
	char buff[BUFSIZE] = {"\0"};
	
	if(argc != 2)
	{
		printf("invalid arguments\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("error to open %s file\n",argv[1]);
		return -1;
	}
	
	while((ret = read(fd, buff, BUFSIZE)) > 0)
	{
		write(1, buff, ret);
	}
	
	printf("Symbolic file opened successfully\n");
	
	close(fd);
	
	return 0;
}
