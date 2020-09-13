/*
4. Write a program which accept file name from user and print all information about that file.

input: mydemo.txt

output:
		filename : mydemo.txt
		mode	 : O_RDONLY
		size	 : 234
		offset 	 : 0
		accessTM : -
		modifyTM : -
		Birth    : -
		
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	
	fd = open(argv[1], O_RDWR);
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}
	
	
	printf("File is opened successfully\n");
	printf("FD is : %d\n",fd);
	printf("File opening mode : %d\n",O_RDONLY);
	printf("Opend File Name : %s\n",argv[1]);
	//req other field names
	
	close(fd);
	
	printf("\n");

	return 0;
}
