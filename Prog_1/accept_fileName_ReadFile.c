/*
8. Write a program which accept file name from user and read whole file.

input: MyInfo.txt		<------ filename
	  
	   MyInfo.txt  contains
	   "Jai Shree Ganasha"

output: 
		Enter file name: MyInfo.txt
		Data read successfully from MyInfo.txt file
		Data is: Jai Shree Ganesha

		Jai Shree Ganasha   <-------- 6 chars red
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
	
	char arr[20];
	int fd;
	char buff[252];

	printf("Enter file name: ");
	scanf("%s",arr);

	fd = open(arr, O_RDWR);

	if( fd == -1)
	{
		printf("Umabel to open file\n");
		return -1;
	}


	fd = read(fd , buff, sizeof(buff));//fd points to file and read from file and store into buff with given size

	if( fd == -1)
	{
		printf("Unable to read file\n");
		return -1;
	}

	printf("Data read successfully from %s file\nData is: %s\n",arr, buff);

	close(fd);

	return 0;
}