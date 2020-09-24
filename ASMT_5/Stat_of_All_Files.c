/*
3.	Write a program which accept directory name from user and write information of all regular file in newfile
	and then read the contents from that file.

input:		Raja fileinfo.txt

Raja/
|-- A
|-- Ab
|-- Abc
`-- Abcd

Raja dir contains four files so we need to write all info of each file into ONE file
then read ONE file

*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>

#define MAXSIZE 512

int main(int argc, char *argv[])
{

	int fd,ret1, ret2 = 0;	
	char buff[MAXSIZE];
	char newline[] = "-----------------------------------------------------------------------";
	DIR *dirp = NULL;
	struct dirent *dp = NULL;
	struct stat fileinfo;
	char *ft = NULL;
	char *ptr = NULL;
	
	if(argc != 3 )
	{
		printf("Insufficient argumennts\n");
		return -1;
	}
	
	stat(argv[1], &fileinfo);
	if(! S_ISDIR(fileinfo.st_mode))
	{
		printf("%s dir doen not exists\n",argv[1]);
		return -1;
	}

	dirp = opendir(argv[1]);
	
	if(dirp == NULL)
	{
		printf("Error to open %s dir\n",argv[1]);
		return -1;
	}
	
	printf("Dir opened\n");
	
	fd = open(argv[2], O_WRONLY);
	
	if(fd == -1)
	{
		printf("Error to open %s file\n",argv[2]);
		return -1;
	}
	
	printf("File opened\n");
	
	while( (dp = readdir(dirp))  != NULL)
	{		
		if( strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0 )
		{
			continue;
		}
		

		stat(dp->d_name, &fileinfo);
		
		switch(fileinfo.st_mode & S_IFMT)
		{
			case S_IFREG:
				ft = "Regular type";
				break;
			
			case S_IFDIR:
				ft = "Directory type";
				break;
			
			case S_IFLNK:
				ft = "Softlink";
				break;
			
			case S_IFCHR:
				ft = "Character type";
			
			default:
				ft = "Unknown type";
				break;
		}
		
		char *ptr = (char*)malloc(MAXSIZE);
		
			sprintf(ptr,"FileName\t\t%s\nFileType\t\t%s\nFileInode\t\t%ld\nFileLinks\t\t%ld\nFileSize\t\t%ld\nFileUID\t\t%d\nFileGID :\t\t%d\nFileBlkSize\t\t%ld\n%s\n",dp->d_name, ft,fileinfo.st_ino, fileinfo.st_nlink, fileinfo.st_size,fileinfo.st_uid, fileinfo.st_gid,fileinfo.st_blksize,newline);
		
		ret1 = write(fd, ptr, MAXSIZE);
		
		if(ret1 == -1)
		{
			printf("Error to write record of %s file\n",dp->d_name);
			continue;
		}
		
		printf("%s\n",ptr);				
		free(ptr);
		ret2++;
		
	}
	
	printf("Total %d files data info written\n",ret2);	
	return 0;
}


