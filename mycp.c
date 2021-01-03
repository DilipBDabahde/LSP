/*
in this application we accept existing regular file and copy data of existing regular file into another file which 
gets created at runtime 

$gcc mycp.y -o mycp
$./mycp existingfile newfile

*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include "tlpi_hdr.h"
#include "error_functions.c"

#ifndef BUF_SIZE

#define BUF_SIZE 1024		//already defined in our header file

#endif


int main(int argc, char *argv[])	//accepts arguments from command line
{
	//creating required vars 
	int inputFd, outputFd, openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE]; //create buffers to read/write 
	
	//when arguments count is invalid
	if(argc != 3 || strcmp(argv[1], "--help") == 0)
	{
		usageError("%s old-file new-file\n",argv[0]);
	}
	
	
	//after open call it returns value
	inputFd = open(argv[1], O_RDONLY);
	
	//when open fails
	if(inputFd == -1)
	{
		errExit("Opening file %s\n",argv[1]);
	}
	
	//forming comman flags
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	
	//forming sets of permissions
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;   //rw-rw-rw
	
	//create | open new file to copy data from old file to new file
	outputFd = open(argv[2], openFlags, filePerms);
	
	//when new file gets fails
	if(outputFd == -1)
	{
		errExit("Opening file %s",argv[2]);
	}
	
	//logic of copying data from old file to new file in loop
	
	//reading file 
	while((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
	{
		//writing to file
		if(write(outputFd, buf, numRead) != numRead)
		{
			fatal("Count not write whole buffed\n");
		}
		
		//when read fails
		if(numRead == -1)
		{
			errExit("Read\n");
		}
		
		//close file descriptor  of old file
		if(close(inputFd) == -1)
		{
			errExit("close input\n");
		}
		
		//close file descriptor of new file
		if(close(outputFd) == -1)
		{
			errExit("close output\n");
		}
		
		//process termination
		exit(EXIT_SUCCESS);
	}
}
