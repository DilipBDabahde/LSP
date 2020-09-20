/*
accept file name from user and check that file exists on physical device or not

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>


int main(int argc, char *argv[])
{
	struct stat sb;
	int fd;
	int ret;
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error : to open file\n");
		return -1;
	}
	else if(fd == 0)
	{
		printf("File is not on physical device\n");
	}
	
	ret = fstat(fd, &sb);
	
	if(ret)
	{
		perror("fstat\n");
		return -1;
	}
	
	printf("Physical device value is: %d\n",gnu_dev_major(sb.st_dev));

	close(fd);
	
	return 0;

}
