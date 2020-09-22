/*
accept dirname from user and delete all files ends with '~'

*/


#include<stdio.h>
#include<string.h>
#include<dirent.h> // to read source file directory entries
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

#define MAXSIZE 128

int main(int argc, char *argv[]) 
{
	DIR *dirp = NULL;
	struct dirent *dp = NULL;
	struct stat fileinfo;
	
	char *seePath = NULL;
	
	int  i = 0, icnt = 0;
	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
			
	stat(argv[1], &fileinfo);
	if(! S_ISDIR(fileinfo.st_mode))
	{
		printf("Given directory is not existing\n");
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
			
			stat(dp->d_name, &fileinfo); //struct initializer			
			
			if(S_ISREG(fileinfo.st_mode))
			{
						
				//allcate memory dynamically to store our path
				seePath = (char*)malloc(sizeof(char)*(sizeof(dp->d_name)+sizeof(argv[2]))); 
				
				//write string where seePath is pointing
				sprintf(seePath,"%s/%s",argv[2],dp->d_name);//write path on heap temporary				
				
				i = 0;
				//to stop copying such files which ends with '~' character
				while(seePath[i] != '\0')
				{
					if(seePath[i] == '~')
					{
						remove(dp->d_name);
						icnt++;
						break;
					}
					i++;
				}		
				i = 0;		
				free(seePath);					
			}			
		}
			
		printf("Total files deleted which ends with '~' : %d\n",icnt);
	
	return 0;
}
