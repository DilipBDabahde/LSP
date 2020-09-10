
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	
	//Opening file in Readmode
	fd = open("moon.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("unable to open file\n");
	}
	else
	{
		printf("File is opened with O_RDONLY fd %d\n",fd);
	}
	
	//opening file in Write mode
	
	fd = open("moon.txt", O_WRONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
	}
	else
	{
		printf("File is opened with O_WRONLY fd %d\n",fd);
	}	
	
	//opening file in RDWR mode
	
	fd = open("moon.txt", O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file\n");
	}
	else
	{
		printf("File is open with O_RDWR fd %d\n",fd);
	}
	
	
	//open filein append mode
	fd = open("moon.txt", O_RDWR | O_APPEND);
	if(fd == -1)
	{
		printf("Unable to open\n");
	}
	else
	{
		printf("File is opened with  O_RDWR | O_APPEND fd %d\n",fd);
	}
	
	
	//open file in O_CREAT mode if not exit then cr
	fd = open("C++.txt",O_RDWR | O_CREAT);
	if(fd == -1)
	{
		printf("Unable to create file\n");
	}
	else
	{
		printf("File opened with fd %d\n", fd);
	}
	
	
	//open with O_EXCL it works with O_CREAT
	//when opening is not exit 
	
	fd = open("java.txt", O_RDWR | O_CREAT | O_EXCL);
	if(fd == -1)
	{
		printf("Unable to open\n");
	}
	else
	{
		printf("File is opened with %d\n",fd);
	}
	
	//O_TRUNC file which set length 0 
	fd = open("moon.txt", O_WRONLY | O_TRUNC);
	if(fd == -1)
	{
		printf("moon can't trunc now\n");	  	
	}
	else
	{
		printf("Moon is trunc now\n");
	}
	
	return 0;
}	
	
	
	
	
