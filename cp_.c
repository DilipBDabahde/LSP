/*
in this application accept existing file and create new copy of that file

$gcc mycp.c -o mycp
$./mycp existfile newfile

newfile will be copy of existfile
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


#define BUFFSIZE 512


void usage()
{
	printf("Usage: ./myexe oldfile newfile\n");
}

int main(int argc, char *argv[])
{
	int fd = 0, ret = 0;
	int fd2 = 0;
	char buff[BUFFSIZE] = {'\0'};
	
	if(argc != 3)
	{
		printf("invalid argumets\n");
		usage();
		return -1;
	}
	
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open %s file\n",argv[1]);
		return -1;
	}
	
	fd2 = creat(argv[2], 0666);
	
	if(fd2 == -1)
	{
		printf("creat fail to create file %s\n",argv[2]);
		return -1;
	}
	else
	{
		printf("%s file gets created\n",argv[2]);
	}
	
	while((ret = read(fd, buff, BUFFSIZE)) > 0)
	{
		if(write(fd2, buff, ret) != ret)
		{
			write(1, "write fails\n", strlen("write fails\n"));
			return -1;
		}
	}
	
	printf("data gets written from %s to %s files\n",argv[1], argv[2]);
	
	if(close(fd) == -1)
	{
		printf("error to close %d fd\n",fd);
		return -1;
	}
	
	if(close(fd2) == -1)
	{
		printf("error to close %d fd\n",fd2);
		return -1;
	}

	
	return 0;
}
