/*
7. Write program which accept directory name from user and delete all empty files from that	directory.


*/

#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	DIR *dirp = NULL;
	struct dirent *dp = NULL;
	struct stat fileinfo;
	int icnt = 0;
	char *ptr = NULL;
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	stat(argv[1], &fileinfo); //object get initialized
	
	if(! S_ISDIR(fileinfo.st_mode))
	{
		printf("%s directory is not existing\n",argv[1]);
		return -1;
	}
	
	dirp = opendir(argv[1]);
	
	if(dirp == NULL)
	{
		printf("Error to open directory\n");
		return -1;
	}
	
	while( (dp = readdir(dirp)) != NULL )
	{
		
		ptr = (char*)malloc(sizeof(char)*(sizeof(argv[1])+sizeof(dp->d_name)));
		
		sprintf(ptr, "%s/%s", argv[1], dp->d_name);
		
		printf("%s\n",ptr);
		
		stat(ptr, &fileinfo);
		
		if(fileinfo.st_size == 0)
		{
			remove(ptr);
			icnt++;
		}
		
		free(ptr);
	}
	
	printf("Total deleted empty files : %d\n",icnt);

	return 0;
}
