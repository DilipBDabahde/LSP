/*
4. Write a program which map any file in memory and read the data from that mapped file.
	
	step1 : accept file name from user and open file in read more 
	step2 : call to stat / fstat fucntion to get size of file
	step3 : pass size and file discriptor to mmap function to map file in memory
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

int main(int argc, char *argv[])
{

	struct stat sobj;
	int fd;
	unsigned int i;
	char *ptr = NULL;
	
	if(argc != 2)
	{
		printf("invalid argument count\n");
		exit(-1);
	}
	
	
	//opening file	
	fd = open(argv[1], O_RDONLY);	
	if(fd == -1)
	{	
		printf("error to open file\n");
		exit(-1);	
	}
	
	//get info of file into struct stat object as inode meta data
	if(stat(argv[1], &sobj) == -1)
	{
		printf("error to get inode meta data into obj\n");
		close(fd);
		exit(-1);
	}
	
	printf("size of file : %ld\n",sobj.st_size);

	
	//chk file type	
	if(! S_ISREG(sobj.st_mode))
	{
		printf("given file is not regular file\n");
		close(fd);
		exit(-1);
	}
	
	
	//getting address of mapped file into memory
	
	ptr = mmap(0,  //req to kernal to start memory map from 0 address
			   sobj.st_size, //size of file	
			   PROT_READ,    //MEM MAP done only for read 
			   MAP_PRIVATE,	//READ AND WRITE CAN DONE
			   fd,			//using this fd file reads till given size
			   0); //memory map of whole size
	
	if(ptr == NULL)
	{
		printf("mmap failed\n");
		close(fd);
		exit(-1);
	}
	
	//now closing opened fd
	if(close(fd) == -1)
	{
		printf("error to close fd\n");
		free(ptr);
		exit(-1);
	}

	//now read data from memory after closed fd
	
	for(i = 0; i < sobj.st_size; i++)
	{
		printf("%c",ptr[i]); //one by one byte is read
	}
	

 	//free memory mapped
	if(munmap(ptr, sobj.st_size) == -1) 
	{
		printf("munmap failed");
		close(fd);
		exit(-1);
	}

	exit(EXIT_SUCCESS);
}
