/*
1. Write a program which writes structure in file. Structure should contains information of	Employee

input:	struct Employee
		{	
			char name[40];
			int empid;
			float salary;
		};
		
		create program to write this above structre in demo.txt file


accept new filename and create it and open to write structure in it

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>		
#include<sys/stat.h>  //to create new file



int main(int argc, char *argv[])
{
	
	//this char array contains infomation Employee structure
	
	int ret, fd;
	
	char buff[] = "struct Employee\n{\n\tchar name[40];\n\tint empid;\n\tfloat salary;\t\n};\n";
	
	fd = creat(argv[1], 0777);
	
	if(fd == -1)
	{
		printf("Errror to create file\n");
		return -1;
	}
	
	printf("File created successfully\n");
	
	fd = open(argv[1], O_WRONLY);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		return fd;
	}
	
	
	//writting structure info  to file
	
	ret = write(fd, buff, sizeof(buff));
	
	if(ret == -1)
	{
		printf("Error to write structure info into file\n");
		return ret;
	}
	
	printf("Structure info successfully written to file\n");
	
	close(fd);
	
	return 0;

}
