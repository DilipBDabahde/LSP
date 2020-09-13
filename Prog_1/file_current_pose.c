/*
in this function we get file opened for read/write to get
current pose 
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;

	long pos;

	fp1 = fopen("mydemo.txt", "w"); //first open call

	fprintf(fp1, "Hello world");

	
	if(fp1 == NULL)
	{
		printf("Unable to oepn file\n");
	}

	fp2 = fopen("mydemo.txt", "a");

	if(fp2 == NULL)
	{
		printf("Unable to open the file\n");
	}

	//ftell function return file current position

	pos = ftell(fp1);
	printf("Current offset if file is opened in read mode %ld\n",pos);
	
	pos = ftell(fp2);
	printf("Current offset if file is opened in append mode is %ld\n",pos);


	//close opened files
	fclose(fp1);
	fclose(fp2);

	return 0;
}