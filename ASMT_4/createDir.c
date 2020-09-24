/*
2. Write a aprogram which accept directory name from user and create new directory of that	name.

input: MyDemo
							MyDemo
							___________________________
						   |file name		|Inode Num |
						   |________________|__________|
						   |________________|__________|
						   |________________|__________|
						   |________________|__________|
						   |________________|__________|
						   |________________|__________|
                           |________________|__________|
*/

#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	
	int ret;
	
	if(argc != 2)
	{
		perror("Insufficient arguments\n");
		exit(-1);
	}
	
	ret = mkdir(argv[1], 0777);
	
	if(ret)
	{
		perror("Error to create directory\n");
		return -1;
	}
	
	printf("Directory creaated successfully\n");	

	return 0;
}

