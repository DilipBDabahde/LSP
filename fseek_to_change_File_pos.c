/*
fseek function is used to change the file position which is used for further reading or writing.
*/


#include<stdio.h>

int main()
{

	FILE *fp = NULL;
	int ret;
	char ch;
	
	fp = fopen("Demo.txt", "r+");
	
	if(fp == NULL)
	{
		printf("Unable to open file\n");
	}
	
	//print file contents
	
	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c",ch);
	}

	//kitine seek kraaycha = 2
	//from where seek start = SEEK_SET  which is 0
	ret = fseek(fp, 2, SEEK_SET);
	
	if(ret == -1)
	{
		printf("unable to seek\n");
	}
	
	//write to file
	
	char arr[] = "I am here for nation service";
	
	fputc('Z', fp); //after setting seek to 2 then write z at there
	fputc('X', fp); //to read and write operation write from 2 
	
	printf("File contents before seek are\n");
	fseek(fp, 0, SEEK_SET); //here again we can read and write from start of file

	rewind(fp);
	
	///printing after rewind
	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c",ch);
	}
	
		
	return 0;
}
