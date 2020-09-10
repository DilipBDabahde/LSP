//O_TRUNC 

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	
	int fd;
	
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
	
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	printf("File Open Sucessfully\nAnd truncated file contents\n");

	close(fd);


	return 0;
}
