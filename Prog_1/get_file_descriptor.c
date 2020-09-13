
//retriving file descriptor using file pointer
/*
	in this prog we used fp whiich gives are fd but
	in this prog we opend one file two times after open 
	first time we got fd as 3 and we did not closed opened file

	and again open same file with same fp we got 4 fd
	bcs file tables are created two times for each open call 4r3

	but instead of this is we open first time file and once we 
	get file descriptor then close that file and open it we 
	get two times same fd as 3 bcs
	first open call return fd as 3 bcs in file table entry
	gets created after used if we close then entry rm
	then second time open call again new entry created in file 
	table so that two times we get back 3 as fd of file. 4r3	
*/
#include<stdio.h>

int main()
{
	FILE *fp = NULL;
	int fd;

	//open file
	fp = fopen("mydemo.txt", "r");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
		return -1;
	}

	//this below function return file fd which is allocated for file
	
	fd = fileno(fp);

	if(fd == -1)
	{
		printf("Unable to get file descriptor\n");
		return -1;
	}

	printf("File descriptor is : %d\n",fd); //3

	fclose(fp);
	
	fp = fopen("mydemo.txt", "r");

	if(fp == NULL)
	{
		printf("Unable to open file\n");
		return -1;
	}

	//getting fd using fp bcs fp has address of opend file

	fd = fileno(fp);

	printf("File descriptor is :%d\n",fd);

	fclose(fp);


	return 0;
}