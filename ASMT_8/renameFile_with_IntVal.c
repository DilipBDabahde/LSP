/*
3. Write a program which creates one process which accept one directory name. That
   process will rename all names of regular files with sequential number. (1.txt, 2.txt,3.txt, 4.txt etc).
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{	
	
	struct stat fileinfo;
	struct dirent *dir;
	DIR *dp;
	pid_t pid;
	
	if(argc != 2)
	{
		printf("invalid arguments\n");
		return -1;
	}
	
	pid = fork();
	
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		printf("child pid: %d\n",getpid());
		dp = opendir(argv[1]);
		
		if(dp == NULL)
		{
			perror("opendir");
			return -1;
		}
		
		int i = 1;
		while((dir = readdir(dp)) != NULL)
		{
			char *path1 = malloc(255);			
			sprintf(path1,"%s/%s",argv[1], dir->d_name);			
			lstat(path1, &fileinfo);
			
			if(strcmp(dir->d_name , ".") == 0 || strcmp(dir->d_name , "..") == 0 || S_ISLNK(fileinfo.st_mode))
			{
				continue;
			}
			
			char *path2 = malloc(255);
			
			sprintf(path2, "%s/%d.txt",argv[1], i);
			
			rename(path1, path2);
			i++;
			free(path1);
			free(path2);
		}
		
		printf("file renamed\n");
	}
	else
	{
		printf("ppid: %d\n",getpid());
		exit(EXIT_SUCCESS);		
	}
	
	return 0;
}
