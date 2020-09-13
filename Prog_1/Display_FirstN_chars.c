/*
7. Write a program which accept file name and read first 5 characters from it.

input: MyInfo.txt		<------ filename
	   6				<------ How many chars want to read from file { lenght }

	   MyInfo.txt  contains
	   "Jai Shree Ganasha"

output: 
		Jai Sh   <-------- 6 chars red


*/
#
include<stdio.h>	// to access io 
#include<unistd.h> //to access sys calls
#include<fcntl.h> //to access flags

int main()
{
	
	FILE *fp = NULL;
	int len = 0;
	int i = 0;

	char arr[20];
	char ch = '\0';


	printf("Enter file name: ");
	scanf("%s",arr);

	printf("Enter chars length to read: ");
	scanf("%d",&len);

	fp = fopen(arr, "r+");

	//len = fread(fp, buff, sizeof(buff)); //fp pointer to file reading into buff

	while((ch = fgetc(fp)) !=  EOF && (i < len))
	{
		printf("%c",ch);
		i++;
	}

	fclose(fp);

	printf("\n");
	
	return 0;	
}