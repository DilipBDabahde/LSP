/*
accept file name from user and read data of the file

$ gcc readfile.c -o myexe
$ ./myexe mydemo.txt

data will read from "mydemo.txt" file depends on given len which is third parameter of prototype

*/
//reading file


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
		
	int fd;
	char buff[45];
	int iret = 0;
	int len = sizeof(buff);
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error : unalble to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File open successfully fd is %d\n",fd);
	
	iret = read(fd, buff, len);
	
	if(iret == -1)
	{
		printf("Error: Unable to read file\n");
		close(fd);
		return -1;
	}
	
	printf("data read successfully %d\n%s\n",iret,buff);
	
	close(fd);
	
	printf("File close successfully fd is %d\n",fd);
	
		
	return 0;
}
