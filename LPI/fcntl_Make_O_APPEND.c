/*
in this program instead of using O_APPEND flag with open we used fcntl function to chage behaviour of fd and work
like O_APPEND flag
*/
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

#define MAX_SIZE 1024
char buff[MAX_SIZE];
char strx[]  = "Sachine is a boy";
char str[] = "We play in school";


int  main(int argc, char const *argv[])
{
	int fd;
	int ret, flags, accessMode;

	fd  = open(argv[1], O_WRONLY );

	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}

	printf("File opened successfully\n");

	//chaning flags

	flags = fcntl(fd, F_GETFL);

	if(flags == -1)
	{
		printf("fcntl error\n");
		close(flags);
	}

	flags |= O_APPEND;

	if(fcntl(fd, F_SETFL, flags) == -1)
	{
		printf("Unable to set flags\n");
		close(fd);
		return -1;
	}
	//by using fcntl we can modify behaviour of fd

	
	if(write(fd, str, sizeof(str)) == -1)
	{
		printf("Unable to write\n");
	}

	if(write(fd, strx, sizeof(strx)) == -1)
	{
		printf("Unable to write\n");
	}

	close(fd);

	return 0;
}
