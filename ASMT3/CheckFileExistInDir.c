/*
5. Write a program which accept directory name and file name from user and check whether that file is present in that directory or not
		Dirname	  Filename
input: MyDir	abc.c
		|
		|a.c
		|abcd.c
		|abc.c

output:
		Given filename is exsiting in given dirname
		
*/



#include<stdio.h>
#include<dirent.h>
#include<string.h>


int main(int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *dp;

	printf("Given Dirname is: %s\n",argv[1]);
	printf("Given filename is: %s\n\n",argv[2]);
	
	
	dirp = opendir(argv[1]);
	
	if(dirp == NULL)
	{
		printf("Error to opendir\n");
		closedir(dirp);
		return -1;
	}
	
	printf("Dir is opened sucessfully\n");
	
	dp = readdir(dirp);
	
	while(dp != NULL)
	{
		if(strcmp(dp->d_name, argv[2]) == 0)
		{
			break;
		}
		dp = readdir(dirp);
	}
	
	if(dp == NULL)
	{
		printf("Given filename is not existing in given dirname\n");
	}
	else
	{
		printf("Given filename is existing in given dirname\n");
	}	
	
	closedir(dirp);
		
	return 0;
}


