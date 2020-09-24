/*
1. Write a program in which Structure should contains information of Employee  and writes structure in file.

accept file name from user in which record is being stored.

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
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 512

struct Employee
{	
	int id;
	float salary;
	char name[40];
};
		


int main(int argc, char *argv[])
{
	
	int fd, ret;
	
	
	//check argument count	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	
	
	//create file and open it
	
	fd = creat(argv[1], 0777);			//creating new file
	
	if(fd == -1)
	{
		printf("Errror to create file\n");
		return -1;
	}
	
	printf("%s : File created successfully\n",argv[1]);
	
	fd = open(argv[1], O_WRONLY);		//opening created file
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		return fd;
	}	
		
		
		
		
	//Creating employee details to write into file
	
	struct Employee emp;	
	
	printf("Enter Emp name: ");
	scanf("%[^'\n']s",emp.name);
		
	printf("Enter Emp id: ");
	scanf("%d",&emp.id);
	
	printf("Enter Emp salary: ");
	scanf("%f",&emp.salary);
	
	char *buff = (char*)malloc(sizeof(emp));
	
	sprintf(buff, "Emp name is: %s\nEmpid is:%d\nEmpSal is: %.2f\n",emp.name, emp.id, emp.salary);
	
	ret = write(fd, buff, MAXSIZE);
	
	if(ret == -1)
	{
		printf("Error to write data into file\n");
		return -1;
	}
	
	printf("Employee data writtten into \"%s\" file\n",argv[1]);
	
	close(fd);
	free(buff);		
		
		
	return 0;

}
