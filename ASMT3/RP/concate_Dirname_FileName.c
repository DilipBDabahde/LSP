/*

accept two dirname from user and copy all files names from source dir to destination directory 
do not read data / write data just create files

*/


#include<stdio.h>
#include<string.h>
#include<dirent.h> // to read source file directory entries
#include<stdlib.h>


int main(int argc, char *argv[]) 
{
	DIR *dirp = NULL;
	struct dirent *dp = NULL;
	char *seePath = NULL;
	
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	
	dirp = opendir(argv[1]);
	
	if(dirp == NULL)
	{
		printf("Error to open dir \n");
		return -1;
	}
	
	//just concate dirpath+filename we donot physically create file on destination
	while( (dp = readdir(dirp)) != NULL)
		{
			if(	strcmp(dp->d_name, ".") == 0 ||		strcmp(dp->d_name, "..") == 0)
			{
				continue;
			}
			
			seePath = (char*)malloc(sizeof(char)*(sizeof(dp->d_name)+sizeof(argv[2]))); //allcate memory dynamically to
																					//store our path
			sprintf(seePath,"%s%s",argv[2],dp->d_name);			
			printf("%s\n",seePath);	
			free(seePath);			
		}
			
	return 0;
}
