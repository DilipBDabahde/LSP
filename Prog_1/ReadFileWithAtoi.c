/*
accept file name and size to read that much bytes from given file
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	char *p = NULL;
	int fd;
	int ret;
	
	if(argc != 3)
	{
		printf("Insuffiend arguments\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}
	
	p = (char*)malloc(sizeof(char)*atoi(argv[2])); //dynamic memory allocation
	
	if( p == NULL)
	{
		printf("No memory allocatedd\n");
		close(fd);
		return -1;
	}
	
	
	
	ret = read(fd, p, atoi(argv[2]));
	
	if(ret == -1)
	{
		printf("Error to read file\n");
		close(fd);
		free(p);
		return -1;
	}
	
	printf("Data read from file is : %s\n",p);
	
	close(fd);
	free(p);
	
	
	return 0;
}	
