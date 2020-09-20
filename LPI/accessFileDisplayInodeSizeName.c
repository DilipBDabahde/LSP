/*
accept fiile name from user and dispaly its inode number name ans size using stat fuction 
on sucess return 0
on error return -1

*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{

	if(access(argv[1], R_OK) < 0)
	{
		printf("Error to access file\n");
		return -1;
	}
	else
	{
		printf("File is accessd with R_OK\n");
	}

	struct stat Obj1;
	int ret = stat(argv[1], &Obj1);  //stat struct will be initiated with given file name 
						   //and gets back initiated obj of stat struct

	printf("File Name : %s\nFile Inode : %ld\n",argv[1], Obj1.st_ino);
	printf("File size is : %ld\n",Obj1.st_size);
	
	
	return 0;
}


