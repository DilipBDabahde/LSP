/*
accept file name from user and write data to file

$ gcc write_into_file.c -o myexe
$ ./myexe mydemo.txt/filepath   

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	
	int fd;
	char str[] = "I love the world"; //18Chars
	int iret = 0;
	int len = sizeof(str);
	
	fd = open(argv[1], O_WRONLY);
	
	if(fd == -1)
	{
		printf("Error : Unable to open file\n");
		close(fd);
		return -1;
	}
	
	printf("File is opened successfullyfd is : %d\n",fd);
	
	iret = write(fd, str, len);
	
	if(iret == -1)
	{
		printf("Error :Unable to file\n");
		close(fd);
		return -1;
	}
	
	printf("data gets written into file fd is %d\n",fd);
	printf("Written data is :--> %s\n",str);
	
	close(fd);
	
	printf("File closed successfully fd is %d\n",fd);

	return 0;
}
