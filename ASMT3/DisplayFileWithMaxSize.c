/*
3. Write a program which accept directory name from user and print name of such a file having largest size.

input:  MyDir
			--|a.c		0
			  |b.c  	4kb
			  |ab.c		2kb
			  |abc.c    3kb

output:
	b.c   4kb <-------- is largest size
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

//DisplayFileWithMaxSize.c

int main(int argc, char *argv[])
{

	DIR *dirp;
	struct dirent *dp;
	struct dirent *dpx;
	struct stat filedata;
	struct stat *sp;
	
	off_t size;
	
	
	//first open dir
	
	dirp = opendir(argv[1]); //help to open dir
	
	dp = readdir(dirp); //step by step getting file address
	
	while(dp != NULL)
	{
	
		
		stat(dp->d_name, &filedata); //filedata object initilization
		sp = &filedata; //			Once object is initiated then pass it's address to same type ptr
		
		if(sp == NULL)
		{
			break;
		}
		
		if(sp->st_size > size)
		{
			size = sp->st_size;
			dpx = dp;			
		}
		
		dp = readdir(dirp);
	}
	
	
	printf("Largest file is : %s\t\tsize is:%ld\n",dpx->d_name, size);
	
	closedir(dirp);
	
	return 0;
}
