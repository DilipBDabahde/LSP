/*
accept file name from user and change its access permission

input: demo.c 0777/0000/0700/...

*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	
	int ret;
	
	ret = chmod(argv[1], atoi(argv[2]));
	
	if(ret == -1)
	{
		printf("Error to set file permission\n");
		return -1;
	}
	
	printf("File permission set successfully\n");

	return 0;
}

