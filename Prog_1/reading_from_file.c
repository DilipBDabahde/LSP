//reading file data

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(void)
{
		
		int fd;
		int ret;
		int offset;
		char buff[200];


	fd = open("mydemo.txt", O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}


	//read 20 chars into buff where fd is pointer to file table
	ret = read(fd, buff, 20); 

	if(ret != 20)
	{
		printf("Unable to read file\n");
	}

	offset  = lseek(fd, 0, SEEK_CUR);

	printf("After reading 20 bytes current byte offset is %d\n", offset);

	return 0;


}
