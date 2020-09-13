/*
9. Write a program which accept filename and string  from user  and write that string into file.

USE : using CMD line interface (cli)

input: MyInfo.txt		<------ filename
	   "Lord Shiva"
	  
	   MyInfo.txt  contains   Before write
	   "Jai Shree Ganasha"	  After write
	    Jai Shree Ganesha Lord Shiva 

output: 
		Enter file name: MyInfo.txt
		Data read successfully from MyInfo.txt file
		Data is: Jai Shree Ganesha Lord Shiva

Enter file name: input.txt
Accept String: Marvellous
Filename : input.txt
String : Marvellous
Length : 10
File descriptor is : 3
Marvellous String  written successfully into file


*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{

	FILE *fp;
	char fname[256];
	char str[20];
	int len = 0;
	int fd;
	int ret;


	printf("Enter file name: ");																
	scanf("%s",fname);


	printf("Accept String: ");
	scanf("%s",str);

	while(str[len] != '\0')
	{
		len++;
	}

	printf("Filename : %s\nString : %s\nLength : %d\n",fname, str, len);


	fp = fopen(fname, "a+");

	if(fp == NULL)
	{
		printf("Unable to open file\n");
	}

	//getting file descriptor of file
	fd = fileno(fp);
	printf("File descriptor is : %d\n", fd);

	//writing to file

	ret = write(fd, str, len);

	if(ret != len)
	{
		printf("Unable to write\n");
		return -1;
	}

	printf("%s String  written successfully into file\n",str);

	close(fd);
	fclose(fp);


	return 0;	
}