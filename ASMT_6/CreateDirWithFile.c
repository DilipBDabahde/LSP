/*
3. Write a aprogram which accept directory name and file name from user and create file in	that directory.


*/


#include<stdio.h>
#include<fcntl.h> //creat file
#include<sys/stat.h> //to creat dir
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[] ) //array of pointer
{
	
	int ret;
	char *ptr = NULL;
	
	
	ret = mkdir(argv[1], 0777);
	
	if(ret == -1)
	{
		printf("Error to create dir\n");
		return -1;
	}
	
	//dynamic memory allcotion for path
	ptr =(char*)malloc(sizeof(char)*(strlen(argv[1])+ strlen(argv[2])));
	sprintf(ptr,"%s/%s",argv[1],argv[2]); //write path on heap
	
	ret = creat(ptr, 0777);
	
	if(ret == -1)
	{
		printf("Error to creat file\n");
		return -1;
	}
	
	printf("Directorya and file created on Path : %s\n",ptr);
	
	free(ptr);	
	
	return 0;
}
