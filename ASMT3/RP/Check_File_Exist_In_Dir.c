/*
5. Write a program which accept directory name and file name from user and 
  check whether that file is present in that directory or not.


*/


#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
	
	DIR *dirp = NULL;
	struct dirent *dp = NULL;
	int fd = 0;
	
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	
	dirp = opendir(argv[1]);
	
	if(dirp == NULL)
	{
		printf("Error to open directory\n");
		return -1;
	}
	
	while( (dp = readdir(dirp)) != NULL)
	{
	  	if(		strcmp(dp->d_name, argv[2]) == 0 	)
	  	{
	  		fd++;
	  		dp = NULL;
	  		break;
	  	}
	}
	
	if(fd != 0)
	{
		printf("%s file exists into %s directory\n",argv[2], argv[1]);
	}
	else
	{
		printf("File does not existing into given directory\n");
	}
	
	closedir(dirp);

	return 0;
}
