/*
5. Write a program which accept file name from user and open that file. + 
6. Write a program which accept file name from user and open that file and if file is not
opened properly then display error message properly

input: input.txt  <------------is existing file
output: input.txt file opened successfully

*/


#include<stdio.h> //IO operation
#include<unistd.h> // sys call
#include<fcntl.h> //to get flags acees

int main(int argc, char *argv[])
{
	int fd;

	char arr[20];

	printf("Enter file name: ");
	scanf("%s",arr);

	fd = open(arr, O_RDWR);

	if( fd == -1)
	{
			printf("unable to open file\n");
			return -1;
	}

	printf("%s file opened Successfully\n",arr);

	close(fd);

	return 0;
}