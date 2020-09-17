#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


#define BUFFSIZE 1024

int main(int argc, char *argv[])
{
	int fd;
	char buff[BUFFSIZE];
	int ret;
	int status;


	fd = open(argv[1], O_RDONLY);

	if(fd == -1)
	{
		printf("Error :  to open file\n");
		close(fd);
		return -1;
	}

	printf("File opened successfull fd is %d\n",fd);

	ret = read(fd, buff, BUFFSIZE); 

	if(ret == -1)
	{
		printf("Error : to read file\n");
		close(fd);
		return -1;
	}

	printf("File data is read successfully\n");
	printf("%s\n",buff);
	printf("Bytes red %d\n",ret);

	status = close(fd);
	printf("File close status %d\n",status);


	return 0;
}