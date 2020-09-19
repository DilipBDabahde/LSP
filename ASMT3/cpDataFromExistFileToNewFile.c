/*
4. Write a program which accept two file names from user and copy the contents of an existing file into newly created file

in this program we can make copy of mp3 as well as video

*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
	
#define BUFF_SIZE 1024

char arr[BUFF_SIZE];


int main(int argc, char *argv[])
{
	int fd, ret;
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		close(fd);
		return -1;
	}
	printf("File Opened successfully\n");
	
	ret = read(fd, arr, sizeof(arr));
	
	if(ret == -1)
	{
		printf("Error to read file\n");
		close(ret);
		return -1;
	}
	
	fd = close(fd);
	
	fd = creat(argv[2], 0777);
	
	if(fd == -1)
	{
		printf("Error to create new file\n");
		close(fd);
		return -1;
	}
	
	printf("New file created : %s\n",argv[2]);
	
	ret = write(fd, arr, sizeof(arr));
	
	if(ret == -1)
	{
		printf("Error to write into newcreated file\n");
		close(ret);
		return -1;
	}
	
	
	printf("Succssfully written data to new created file\n");
	
	close(fd);
	
	return 0;
}
