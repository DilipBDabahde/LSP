/*
2. Write a program which accept directory name from user and print all file names and its types from that directory

*/

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{

	DIR *dirp = NULL;  //it helps to point out targeted directory
	struct dirent *dirfile = NULL; // it helps to point entries which are in targeted directory
	struct stat fileinfo;
	int icnt = 0;
	
	//opening directory
	
	dirp = opendir(argv[1]); // this function return address of targeted directory
	
	if(dirp == NULL)	//if dirp did not get address then it gets in 
	{
		printf("Error to open directory\n");
		return -1;
	}
	
	while( (dirfile = readdir(dirp)) != NULL)
	{
		if( strcmp(dirfile->d_name, ".") == 0 || strcmp(dirfile->d_name, "..") == 0)
		{
			continue;
		}
		
		printf("%s\t\t\t\t",dirfile->d_name);
		
		stat(dirfile->d_name, &fileinfo);
			
		printf("%d\n",fileinfo.st_mode);
		if(S_ISDIR(fileinfo.st_mode))
		{
			printf("Directory file\n");
		}
		else if(S_ISREG(fileinfo.st_mode))
		{
			printf("Regular file\n");
		}
		else if(S_ISLNK(fileinfo.st_mode))
		{
			printf("Symbolik link\n");
		}
		else if(S_ISCHR(fileinfo.st_mode))
		{
			printf("Character file\n");
		}
		else
		{
			printf("Unknown mode\n");
		}
		
		icnt++;
	}
	
	printf("\nTotal files in given directory is: %d\n",icnt);
	closedir(dirp);

	return 0;
}
