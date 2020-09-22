/*
1. Write a program which accept directory name from user and print all file names from that	directory.
input:  .   Current directory

output:	
.
|-- README
|-- README~
|-- a.out
|-- displayAllFiles.c
|-- displayAllFiles.c~
|-- makefile
|-- makefile~
`-- myexe1

*/


#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int icnt = 0;
	DIR *dirp;				//DIR struct pointer
	struct dirent *dirfile; // each directory contains entries of files with their inode number
	
	dirp = opendir(argv[1]); //this function return address of targeted directory 
	
	if(dirp == NULL) 	//if dirp does not get address of target directory get exits with message
	{
		printf("Error to open directory\n");
		return -1;
	}
	
	printf("Given directory is opened successfully\n\n");
	
	while( (dirfile = readdir(dirp)) != NULL) //iterate till dirfile become null
	{
		if( strcmp(dirfile->d_name, ".") == 0  || strcmp(dirfile->d_name, "..") == 0 )
		{
			continue;
		}
		
		icnt++;
		printf("%s\n",dirfile->d_name);		
	}
	printf("\nTotal files in given dir is : %d\n",icnt);
	
	closedir(dirp); //deallocated resource
	printf("\n\n");
	
	
	return 0;
}

