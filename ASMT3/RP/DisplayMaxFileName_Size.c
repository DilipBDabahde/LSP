/*
3. Write a program which accept directory name from user and print name of such a file	having largest size.

*/

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{	
	DIR *dirp = NULL;
	struct dirent *dp = NULL;
	struct stat fileinfo;
	long int size = 0;
	char *ptr = NULL;
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}

	dirp = opendir(argv[1]);
	
	if(dirp == NULL)
	{
		printf("Error to open directory\n");
		return -1;
	}
	
	while( (dp = readdir(dirp)) != 0)
	{
		stat(dp->d_name, &fileinfo);
		
		if(fileinfo.st_size > size)
		{
			size = fileinfo.st_size;
			ptr = dp->d_name;
		}	
	}
	
	printf("File name : %s\t\tFileMax Size: %ld\n",ptr,size);
	
	closedir(dirp);
	
	return 0;
}
