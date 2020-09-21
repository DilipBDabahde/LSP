/*
1. Write a program which accept directory name from user and print all file names from that	directory.
- opendir
- readdir 			//will return file entry addd as well as dir address which is subdir
- closedir

- struct dirent obj1;
- DIR *dirp

we pass to obj1 to stat(filename, &obj1) gets back filled object

.
|-- Demox
|-- main.c
|-- myp.cpp
`-- puc.java

1 directory, 3 files

*/

#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	
	DIR *dirp;
	struct dirent *dirFilePtr;
	
	
	
	dirp = opendir(argv[1]); //opening dir and return object addresss of DIR struccture OR NULL OR 
	
	if(dirp == NULL)
	{
		printf("Error to open dir\n");
		return -1;
	}
	
	printf("%s Opened Successfully\n",argv[1]);
	
	//display file name & inode number
	while(	(dirFilePtr = readdir(dirp)) != NULL)	
	{
		printf("%s			%ld			\n",dirFilePtr->d_name, dirFilePtr->d_ino);		
	}
	
	closedir(dirp); //closedir by passing dirp pointer which gets free after closedir

	return 0;
}

