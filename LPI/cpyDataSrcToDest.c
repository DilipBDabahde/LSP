/*
accpet exists file name and one newfile and copy data of exsiting file to new file
take file name with command lline arguments

$gcc Demo.c -o myexe
$ ./myexe oldfile newfile

*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <string.h>
#include<sys/stat.h> //to get access of "mode_t"

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	int inputFD, outputFD, openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char Buff[BUF_SIZE];


	if((strcmp(argv[1], "--help") == 0))
	{
		printf("For this operation user has to provide arguments like \n:Existing_file_name and New_FileName\n");
		return -1;
	}

	if(argc != 3 || argc == 1)
	{
		printf("Insufficient arguments\n");
		printf("For help Enter \"--help\" \n");
		return -1;
	}

	inputFD = open(argv[1], O_RDONLY);

	if(inputFD == -1)
	{
		printf("Error unable to open file\n");
		close(inputFD);
		return -1;
	}

	printf("%s File opened Successfully fd is %d\n",argv[1],inputFD);

	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	filePerms = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH ; //rw-rw-rw u-g-o

	outputFD = open(argv[2], openFlags, filePerms);

	if(outputFD == -1)
	{
		printf("Error : Unable to open file \n");
		close(outputFD);
		return -1;
	}

	printf("%s File opend Successfully with fd is %d\n",argv[2],outputFD);


	//code to write src file data to dest file

	while((numRead = read(inputFD, Buff, BUF_SIZE)) > 0)
	{													 //if successfully red then write
			if(write(outputFD, Buff, numRead) != numRead)
			{
				printf("Error : Unable to write data to %s file\n",argv[2]);
			}
	}	

	if(numRead == -1) //if data not red 
	{
		printf("Error : Unable to read data from %s file\n",argv[1]);
		close(inputFD);
		close(outputFD);
		return -1;
	}

	printf("Data copyed Successfully from %s to %s\n",argv[1], argv[2]);

	close(inputFD);
	close(outputFD);

	return 0;
}