/*
acccpet file name from user and if it not existing then create else display its existing
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int  main(int argc, char const *argv[])
{
	
	int fd;
	int ret;

	fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 0777);

	if(fd == -1)
	{
		printf("File is Existing\n");
		close(fd);
		return -1;
	}
	
	printf("New File created successfully\n");

	close(fd);

	return 0;
}