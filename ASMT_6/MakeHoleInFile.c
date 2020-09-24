/*
2. Write a program which create hole of size 1kb at the end of file.

*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	char arr[] = "abcdefghij";   //10 chars + 1
	char brr[] = "ABCDEFGHIJ"; //10 chars + 1 + 1024 = 1046 should be file size
	int fd, ret;
	
	
	fd = open(argv[1], O_WRONLY | O_CREAT , 0777);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		return -1;
	}

	ret = write(fd, arr, sizeof(arr)); //first arr data gets written   //first 10+1
	
	if(ret == -1)
	{
		printf("Error to write\n");
		return -1;
	}
		
	ret = lseek(fd, 1024, SEEK_END); //shifted fd ahead by 1024 bytes // 11+1024
	
	ret = write(fd, brr, sizeof(brr)); //write brr data	// 1035+11
	
	if(ret == -1)
	{
		printf("Error to write\n");
		return -1;
	}
	
	
	close(fd);

	return 0;
}
