/*
6 . Write a program which accept two directory names from user and move all files from source directory 
	to destination directory
	
accept two dirname from user and copy all files names from source dir to destination directory 
do not read data / write data just create files

input: 
	$ gcc test.c
	$ ./a.out sourcedir destdir

*/


#include<stdio.h>
#include<string.h>
#include<dirent.h> // to read source file directory entries
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

#define MAXSIZE 128

int main(int argc, char *argv[]) 
{
	DIR *dirp = NULL;
	struct dirent *dp = NULL;
	struct stat fileinfo;
	char *seePath = NULL;
	char buff[MAXSIZE];
	int fd1, fd2, ret1, ret2, icnt = 0;
	
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	if( S_ISDIR(!argv[1]))
	{
		printf("source dir is not existing\n");
		return -1;
	}
			
	if(S_ISDIR(!argv[2]))
	{
		printf("dest dir is not existing\n");
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
			
			stat(dp->d_name, &fileinfo);
			
			
			if(S_ISREG(fileinfo.st_mode))
			{
						
				//allcate memory dynamically to store our path
				seePath = (char*)malloc(sizeof(char)*(sizeof(dp->d_name)+sizeof(argv[2]))); 
				
				//write string where seePath is pointing
				sprintf(seePath,"%s/%s",argv[2],dp->d_name);//write path on heap temporary				
				
				fd1 = open(dp->d_name, O_RDONLY); //opening file to read data
		
				//if file not opened then go to next file 
				if(fd1 == -1)
				{
					printf("Error to open %s\n",dp->d_name);
					close(fd1);
					close(ret1);
					continue;
				}
				
				
				//create file in target location 
				ret1 = creat(seePath, 0777);
				
				if(ret1 == -1)
				{
					printf("Error to create file \n");
					continue;
				}
				
				//open newly created file from target location
				fd2 = open(seePath, O_WRONLY | O_APPEND);
				
				if(fd2 == -1)
				{
					printf("Error to open %s\n ",seePath);
					close(fd1);
					close(fd2);
					continue;
				}
				
				//read data from srcfile and write it into destination file
				while( (ret1 = read(fd1, buff,MAXSIZE )) > 0)
				{
					if(ret2 = write(fd2, buff, ret1) != ret1)
					{}
				}
				
				if(ret1 == -1)
				{
					printf("Error to read file \n");
					close(fd1);
					close(fd2);
					continue;
				}
				
				if(ret2 == -1)
				{
					printf("Error to write file \n");
					close(fd1);
					close(fd2);
					continue;
				}
				
				close(fd1);
				close(fd2);
				close(ret1);
		
				free(seePath);		
				icnt++;	
			}
			
		}
			
		printf("Total copied files are : %d\n",icnt);
	return 0;
}
