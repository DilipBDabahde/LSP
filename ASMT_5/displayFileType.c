/*
accept file name display its type
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
	struct stat fileinfo;
	
	stat(argv[1], &fileinfo);
	
	if(S_ISREG(fileinfo.st_mode))
	{
		printf("Regular file\n");
	}
	else if(S_ISDIR(fileinfo.st_mode))
	{
		printf("Directory file\n");
	}
	else if(S_ISLNK(fileinfo.st_mode))
	{
		printf("Symbolic link\n");
	}
	else
	{
		printf("Unknown type\n");
	}
	
	return 0;

}
