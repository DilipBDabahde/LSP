/*
	accept file name from user and write some data into file randomly
	instead of lseek(fd,offset,whense) && write(fd,buff,len) use
	pwrite(fd, buff,len, offset)  its fast than (lseek & write) system call
	
	
*/



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
	int fd, ret;
	char buff[] = "abcdefghijklmn";
	
	if(argc != 3)
	{
		printf("insufficient arguments\n");
		return -1;
	}

	//open file
	fd = open(argv[1], O_WRONLY);
	
	if(fd == -1)
	{
		printf("Error to open file with write mode : %s\n",argv[1]);
		close(fd);
		return -1;
	}
	
	printf("File opened successfully to write\n");
	
	//random offset write	
	ret = pwrite(fd, buff, strlen(buff), atoi(argv[2]));
	
	if(ret == -1)
	{
		printf("Error to write file\n");
		close(fd);
		return -1;
	}
	
	printf("total bytes write : %d\n",ret);
	
	close(fd);
	
	return 0;
}
