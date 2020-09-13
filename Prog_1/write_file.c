//write to file

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd;
	int ret;
	int offset;

	char buff[] = "Now i love programming";
	char buff2[sizeof(buff)];


	fd = open("mydemo.txt", O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	//using write sys call to write data

	ret =write(fd, buff, sizeof(buff));

	if(ret != sizeof(buff))
	{
		printf("Unable to write contents\n");
	}

	//set to fd to 0 row 0 col index of file using 0 SEEK_SET
	lseek(fd, 0, SEEK_SET);

	//read file data fd fd points to 0 row 0 col size to read sizeof(buff2)
	ret = read(fd, buff2, sizeof(buff2));

	if(ret != sizeof(buff2))
	{
		printf("unable to read\n");
	}

	printf("Written contents are :%s\n", buff2);

	close(fd);
	close(ret);
	return 0;
}