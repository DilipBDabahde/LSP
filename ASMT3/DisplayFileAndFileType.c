/*
2. Write a program which accept directory name from user and print all file names and its types from that directory.


*/

#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<dirent.h> 

int main(int argc, char *argv[])
{
	
	DIR *dirp;
	struct dirent *dp;
	struct stat filemode;
	struct stat *sb;
	int icnt = 0;
	
	dirp = opendir(argv[1]);
	
	dp = readdir(dirp);
	
	while(dp != NULL)
	{
		
		stat(dp->d_name, &filemode); //inside filemode object of stat struct initialized in....
		sb = &filemode;  			//get address of initialized stat object and pointer and acceses all mems of it
		
		
		printf("FileType: ");
		switch(sb->st_mode & S_IFMT)
		{
			case S_IFREG:
				printf("Regular File\t\t");
				break;			
			case S_IFDIR:
				printf("Directory file\t\t");
				break;
			case S_IFCHR:
				printf("character device\t\t");
				break;
			case S_IFBLK:
				printf("block device\t\t");
				break;
			case S_IFLNK:
				printf("Symbolik (soft) link\t\t");
				break;
			case S_IFIFO:
				printf("FIFO Or PIPE\t\t");
				break;
			case S_IFSOCK:
				printf("Socket\t\t");
				break;			
			default:
				printf("Unknown file type\t\t");
				break;
		}	
		
		printf("Filename: %s\n",dp->d_name);
			
		icnt++;		
		dp = readdir(dirp);		
	}
	
	printf("Total files %d\n",icnt);
	
	closedir(dirp);
	
	return 0;
}
